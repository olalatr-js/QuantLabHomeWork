#include "TradesStreamFile.h"
#include "Trade.h"

TradesStreamFile::TradesStreamFile(const std::string& in_path): m_ifs(in_path)
{
	if (!m_ifs.good())
		throw std::invalid_argument("Failed to open " + in_path);
}

bool TradesStreamFile::GetNext(Trade& trade)
{
	std::string line;
	if (!std::getline(m_ifs, line))
		return false;

	trade.Parse(line);
	return true;
}
