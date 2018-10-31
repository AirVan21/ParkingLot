## ParkingLot
**ParkingLot** is a simple calculation logic which determines the busiest time moment for the parking lot. Every car is registered twice: when it enters the parking lot and when it leaves. Times are registered with the minute precision.

### Build
Execute `make` in the project directory.

### Run
`./main data/simple.txt`

The second argument represents the path to the parking lot schedule file. Example of the schedule is located in the folder *data*.

### Extra
The `scripts` folder contains a python script for simple schedule generation. Execute `python3 generator.py -h` to see how to use it.
