#pragma once

#include <memory>
#include <vector>

#include "Segment.h"
#include "ISegmentReader.h"

/**
 * ParkingLot - class with repesents schedule processing logic
 */
class ParkingLot
{
public:
    ParkingLot(const std::shared_ptr<ISegmentReader>& segmentReader);
    virtual ~ParkingLot() = default;

public:
    /**
     * Returns the busiest minute on the parking lot
     * @return serial number of the busiest minute
     */
    size_t GetBusyMinute() const;

private:
    void ProcessSchedule();
    static bool IsDayCross(const Segment& segment);

private:
    static const size_t             SCHEDULE_LENGTH;
    std::vector<int64_t>            m_schedule;
    std::shared_ptr<ISegmentReader> m_reader;
};
