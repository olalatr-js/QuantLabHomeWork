#pragma once

#include "TradeStatistic.h"
#include <map>
#include <string>

/**
 * @brief Structure which holds the results of trades aggregation.
 */
struct AggregationResult
{
	/**
	 * @brief Saves aggregation results to hard drive in csv format according to the task requirements.
	 *        During calculations double data type is used to keep accuracy for weighted_average_price.
	 *        But at the save stage weighted average price is casted to unsigned int.
	 */
	void Save(const std::string& path_to_save) const;

	std::map<std::string, TradeStatistic> statistics;
};