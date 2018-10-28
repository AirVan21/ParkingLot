#pragma once
#include <vector>

#include "Segment.h"

class ParkingLot
{
public:
    ParkingLot(const std::vector<Segment>& schedule);
    virtual ~ParkingLot() = default;

public:
    size_t GetBusyMinute() const;

private:
    void ProcessSchedule(const std::vector<Segment>& schedule);
    bool IsDayCross(const Segment& segment) const;

private:
    static const size_t  SCHEDULE_LENGTH;
    std::vector<int64_t> m_schedule;
};
