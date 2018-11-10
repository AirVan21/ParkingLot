FLAGS = -std=c++14 -Wall
CC    = g++

all: src/ParkingLot.o src/PlainTextReader.o src/main.cpp
	$(CC) $(FLAGS) src/ParkingLot.o src/PlainTextReader.o src/main.cpp -o main

ParkingLot.o: src/ParkingLot.cpp
	$(CC) $(FLAGS) src/ParkingLot.cpp -o ParkingLot.o

PlainTextReader.o: src/PlainTextReader.cpp
	$(CC) $(FLAGS) src/PlainTextReader.cpp -o PlainTextReader.o

clean:
	rm src/*.o main

.PHONY:
	clean all
