#pragma once

#include "ITradesStream.h"

#include <string>
#include <fstream>

/**
 * @brief Implementation which works with csv file from hard drive
 */
class TradesStreamFile: public ITradesStream
{
public:
	TradesStreamFile(const std::string& in_path);

	bool GetNext(Trade& trade) override;

private:
	std::ifstream m_ifs;
};