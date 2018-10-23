#pragma once
#include <vector>

#include "Segment.h"

class ParkingLot
{
public:
    ParkingLot(const std::vector<Segment>& schedule);
    virtual ~ParkingLot() = default;

private:
    void ProcessSchedule(const std::vector<Segment>& schedule);

private:
    static const size_t SCHEDULE_LENGTH;
    std::vector<size_t> m_schedule;
};
