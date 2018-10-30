#include <iostream>
#include <memory>

#include "ParkingLot.h"
#include "PlainTextReader.h"

int main(int argc, char const *argv[])
{
    using std::endl;
    using std::cout;

    // Asking for path argument
    if (argc < 2)
    {
        cout << "Please, write a local path to the file as a 2nd argument!" << std::endl
             << "Example: ./main data/simple.txt" << std::endl;
        return 0;
    }
    // Using 1st argument as a path
    std::shared_ptr<ISegmentReader> scheduleReader(new PlainTextReader(argv[1]));
    if (!scheduleReader->IsOpen())
    {
        cout << "Schedule file wasn't opened successfully. Please, verify the path." << std::endl;
        return 0;
    }
    // Creates calculation logic
    ParkingLot parkingLot(scheduleReader);
    size_t busyMinute = parkingLot.GetBusyMinute();
    // Printing answer
    cout << "Busiest time moment is ";
    cout << busyMinute / 60 << ":" << busyMinute % 60 << std::endl;

    return 0;
}
