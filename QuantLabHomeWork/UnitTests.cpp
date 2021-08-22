#include "Aggregator.h"
#include "TradesStreamFile.h"

#include <string>
#include <memory>
#include <cassert>

namespace
{
	std::string test_data_folder = "..\\TestData\\";
}

/**
 * @brief Compres content of actual and expected csv files 
 */
void Compare(const std::string& actual_path, const std::string& expected_path)
{
	std::ifstream actual_isf(actual_path);
	if (!actual_isf.good())
		throw std::runtime_error("Failed to open " + actual_path);

	std::string actual_str((std::istreambuf_iterator<char>(actual_isf)), std::istreambuf_iterator<char>());

	std::ifstream expected_isf(expected_path);
	if (!expected_isf.good())
		throw std::runtime_error("Failed to open " + expected_path);

	std::string expected_str((std::istreambuf_iterator<char>(expected_isf)), std::istreambuf_iterator<char>());

	// In production tests we should use some framework like Google Test. But I did not
	// want to plug any third party libraries just to keep home work small and simple.
	assert(actual_str == expected_str);
}

void Test(const std::string& in_path, const std::string& actual_path, const std::string& expected_path)
{
	auto tsf = std::make_shared<TradesStreamFile>(in_path);
	Aggregator agg(tsf);
	const auto result = agg.Run();
	result.Save(actual_path);

	Compare(actual_path, expected_path);
}

void TestPrecission()
{
	double a = 1.e20;
	double b = 100.;
	double c = a + b;

	assert(std::abs(a - c) < DBL_EPSILON);

	// This test shows that a + b == a even if b > 0. This is because C++ double 
	// arithmetic holds only 15 meaningful digits and a and b have different magnitude.
	// This fact will cause calculation problems when we accumulated big volume of trades.
	// Suppose after N steps we have volume[N]*weighted_average_price[N] > 1.e20. Then next
	// trade N+1 comes with volume[N+1]*price[N+1] < 100. In this case
	// volume[N]*weighted_average_price[N] + volume[N+1]*price[N+1] == volume[N]*weighted_average_price[N]
	// and we will fail to calculate weighted_average_price[N+1]

	// I can implement solution for huge volume trades but it will go beyond
	// 2 hours which are allocated for this home work. I even not sure if this is your
	// business case.
}

void RunAllUnitTests()
{
	// Data copied from instruction
	Test(test_data_folder + "sample_input.csv", test_data_folder + "sample_actual.csv", test_data_folder + "sample_expected.csv");

	// My test data
	Test(test_data_folder + "my_input_1.csv", test_data_folder + "my_actual_1.csv", test_data_folder + "my_expected_1.csv");

	TestPrecission();
}

