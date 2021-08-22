#include "Trade.h"

#include <sstream>

void Trade::Parse(const std::string& line)
{
	std::istringstream iss(line);
	std::string token;

	std::getline(iss, token, ',');
	time_stamp = std::stoull(token);

	std::getline(iss, symbol, ',');

	std::getline(iss, token, ',');
	quantity = std::stoul(token);

	std::getline(iss, token);
	price = std::stoul(token);
}
