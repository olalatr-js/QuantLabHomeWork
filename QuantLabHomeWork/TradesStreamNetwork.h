#pragma once

#include "ITradesStream.h"

// Although the provided input file is small, the solution should be able to handle
// a source dataset well beyond the amount memory and hard disk space on your machine.

// Most likely we will have stream of trades which are comming from network.
// We will not store all of them we'll just keep aggregating.

class SomeConnection;

class TradesStreamNetwork : public ITradesStream
{
public:
	TradesStreamNetwork(SomeConnection&);

	bool GetNext(Trade&) override;
};