#include "ParkingLot.h"

const size_t ParkingLot::SCHEDULE_LENGTH = 60 * 24;

ParkingLot::ParkingLot(const std::vector<Segment>& schedule)
    : m_schedule(SCHEDULE_LENGTH, 0)
{
    ProcessSchedule(schedule);
}

void ParkingLot::ProcessSchedule(const std::vector<Segment>& schedule)
{
    for (const auto& segment : schedule)
    {

    }
}
