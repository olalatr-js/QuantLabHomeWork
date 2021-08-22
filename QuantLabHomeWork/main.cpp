#include "Aggregator.h"
#include "TradesStreamFile.h"
#include "UnitTests.h"

#include <string>
#include <map>

void MainRun(const std::string& in_path, const std::string& out_path)
{
	auto tsf = std::make_shared<TradesStreamFile>(in_path);
	Aggregator agg(tsf);
	const auto result = agg.Run();
	result.Save(out_path);
}

int main(int argc, const char* argv[])
{
	// Change next 2 lines to specify location of input csv file and where
	// output csv file will be stored
	std::string in_path("input.csv");
	std::string out_path("output.csv");
	MainRun(in_path, out_path);

	RunAllUnitTests();

	return 0;
}