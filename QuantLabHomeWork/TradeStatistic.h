#pragma once

/**
 * @brief Container to hold results of aggregation calculations per one trade symbol.
 */
struct TradeStatistic
{
	TradeStatistic() = default;
	TradeStatistic(unsigned long long a_max_time_gap, unsigned long long a_volume,
		double a_weighted_average_price, unsigned int a_max_price):
		max_time_gap(a_max_time_gap),
	    volume(a_volume),
	    weighted_average_price(a_weighted_average_price),
	    max_price(a_max_price)
	{}

	unsigned long long max_time_gap{ 0u };
	unsigned long long volume{ 0u };
	double weighted_average_price{ 0u };
	unsigned int max_price{ 0u };
};