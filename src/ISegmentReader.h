#pragma once
#include <vector>

#include "Segment.h"

/**
 * ISegmentReader is an interface class for all scededule readers
 **/
struct ISegmentReader
{
    virtual ~ISegmentReader() {};
    virtual std::vector<Segment> GetSchedule() = 0;
};
