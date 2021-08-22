#pragma once

#include <string>

struct Trade
{
	void Parse(const std::string& line);

	// is value indicating the microseconds since midnight.
	// Since 24 * 60 * 60 * 1 000 000 = 86 400 000 000 = 8.64 * 10^10 > 2^32 = 4 294 967 296
	// we will use unsigned long long
	unsigned long long time_stamp;

	// unique identifier for a financial instrument. Type can be char[3] ?
	std::string symbol;

	// the amount traded
	unsigned long long quantity;

	// price of the trade for that financial instrument
	unsigned int price;
};