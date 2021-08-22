#pragma once

#include "AggregationResult.h"

#include <string>
#include <memory>

class ITradesStream;

/**
 * Class which does main calculations using input stream of trades
 */
class Aggregator
{
public:
	Aggregator(std::shared_ptr<ITradesStream> stream);

	AggregationResult Run();
private:
	std::shared_ptr<ITradesStream> m_stream;
};