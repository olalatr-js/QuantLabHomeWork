#pragma once

struct Trade;

/**
 * @brief Interface which should implement all trade streams so that Aggregator
 *        would be able to process the stream.
 */
class ITradesStream
{
public:
	virtual bool GetNext(Trade&) = 0;
};