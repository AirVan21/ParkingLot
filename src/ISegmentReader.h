#pragma once

#include <vector>

#include "Segment.h"

/**
 * ISegmentReader is an interface class for all scededule readers
 **/
struct ISegmentReader
{
    virtual ~ISegmentReader() {};

    /**
     * Reads time segment
     * @param segment where result will be written
     * @return true if segment was read successfully
     *         false otherwise
     */
    virtual bool GetSegment(Segment& segment) = 0;

    /**
     * Verifies that file was open successfully
     */
    virtual bool IsOpen() const = 0;
};
