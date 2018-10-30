#include "ParkingLot.h"

// Minutes in a day
const size_t ParkingLot::SCHEDULE_LENGTH = 60 * 24;

ParkingLot::ParkingLot(const std::shared_ptr<ISegmentReader>& segmentReader)
    : m_schedule(SCHEDULE_LENGTH, 0)
    , m_reader(segmentReader)

{
    ProcessSchedule();
}

size_t ParkingLot::GetBusyMinute() const
{
    size_t busyMinute = 0;
    int64_t maxAmount = m_schedule.front();
    int64_t amountOfCars = m_schedule.front();
    for (size_t i = 0; i < SCHEDULE_LENGTH; ++i)
    {
        amountOfCars += m_schedule.at(i);
        if (amountOfCars > maxAmount)
        {
            busyMinute = i;
            maxAmount = amountOfCars;
        }
    }
    // Returns most busy minute
    return busyMinute;
}

void ParkingLot::ProcessSchedule()
{
    Segment segment;
    while(m_reader->GetSegment(segment))
    {
        // Time segment edges are taken by module
        size_t minuteStart = segment.m_minuteStart % SCHEDULE_LENGTH;
        size_t minuteEnd = segment.m_minuteEnd % SCHEDULE_LENGTH;
        // Increment on a time segment start
        // Decrement on a time segment end
        ++m_schedule.at(minuteStart);
        // Adds extra increment on day start (if segments crosses midnight)
        --m_schedule.at(minuteEnd);
        if (IsDayCross(segment))
        {
            ++m_schedule.front();
        }
    }
}

bool ParkingLot::IsDayCross(const Segment& segment)
{
    return segment.m_minuteStart > segment.m_minuteEnd;
}
