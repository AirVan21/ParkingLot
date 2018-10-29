#include <iostream>

#include "ParkingLot.h"
#include "PlainTextReader.h"

int main(int argc, char const *argv[])
{
    using std::endl;
    using std::cout;

    if (argc < 2)
    {
        cout << "Please, write a local path to the file as a 2nd argument!" << std::endl
             << "Example: ./main data/simple.txt" << std::endl;
        return 0;
    }
    // Using 1st argument as a path
    PlainTextReader scheduleReader(argv[1]);
    // Creates calculation logic
    ParkingLot parkingLot(scheduleReader.GetSchedule());
    size_t busyMinute = parkingLot.GetBusyMinute();
    // Printing answer
    cout << "Busiest time moment is ";
    cout << busyMinute / 60 << ":" << busyMinute % 60 << std::endl;

    return 0;
}
