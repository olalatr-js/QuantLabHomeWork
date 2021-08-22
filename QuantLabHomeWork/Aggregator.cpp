#include "Aggregator.h"
#include "Trade.h"
#include "TradesStreamFile.h"

#include <algorithm>
#include <unordered_map>

Aggregator::Aggregator(std::shared_ptr<ITradesStream> stream): m_stream(stream)
{
}

AggregationResult Aggregator::Run()
{
	AggregationResult result;
	std::map<std::string, TradeStatistic> stat;
	// time stamp when the trade last time was seen
	std::unordered_map<std::string, unsigned long long> last_seen;

	Trade trade;
	while (m_stream->GetNext(trade))
	{
		if (!last_seen.count(trade.symbol))
		{
			stat.emplace(trade.symbol,
				TradeStatistic(0u, trade.quantity, trade.price, trade.price));
		}
		else
		{
			auto& to_update = stat[trade.symbol];

			to_update.weighted_average_price = 
				(to_update.weighted_average_price * to_update.volume + trade.price * trade.quantity)
				/ (to_update.volume + trade.quantity);

			to_update.max_time_gap = std::max(to_update.max_time_gap,
				trade.time_stamp - last_seen[trade.symbol]);
			to_update.volume += trade.quantity;
			to_update.max_price = std::max(to_update.max_price, trade.price);
		}

		last_seen[trade.symbol] = trade.time_stamp;
	}

	result.statistics = std::move(stat);
	return result;
}