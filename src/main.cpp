#include <iostream>

#include "ParkingLot.h"
#include "PlainTextReader.h"

int main(int argc, char const *argv[])
{
    using std::endl;
    using std::cout;

    if (argc < 2)
    {
        cout << "Please, write local path to file as an argument!" << endl;
        return 0;
    }
    // Using 1st argument as a path
    PlainTextReader scheduleReader(argv[1]);
    // Creates calculation logic
    ParkingLot parkingLot(scheduleReader.GetSchedule());
    size_t busyMinute = parkingLot.GetBusyMinute();
    // Printing answer
    cout << busyMinute / 60 << ":" << busyMinute % 60 << std::endl;

    return 0;
}
