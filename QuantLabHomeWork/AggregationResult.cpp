#include "AggregationResult.h"
#include <fstream>

void AggregationResult::Save(const std::string& path_to_save) const
{
	if (statistics.empty())
		return;

	std::ofstream ofs(path_to_save);
	if (!ofs.good())
		throw std::runtime_error("Failed to save " + path_to_save);

	// Do not want to save empty line at the end of the file. That is why
	// I save first line and later the rest and start adding new line at 
	// the beginning of the cycle
	auto itr = statistics.begin();
	ofs << itr->first << ',' <<
		itr->second.max_time_gap << ',' <<
		itr->second.volume << ',' <<
		static_cast<unsigned>(itr->second.weighted_average_price) << ',' <<
		itr->second.max_price;
	++itr;
	for (; itr != statistics.end(); ++itr)
	{
		ofs << "\n" <<
			itr->first << ',' <<
			itr->second.max_time_gap << ',' <<
			itr->second.volume << ',' <<
			static_cast<unsigned>(itr->second.weighted_average_price) << ',' <<
			itr->second.max_price;
	}
}
