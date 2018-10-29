FLAGS = -std=c++14 -Wall
CC    = g++

all: src/ParkingLot.o src/PlainTextReader.o src/main.cpp
	$(CC) $(FLAGS) src/ParkingLot.o src/PlainTextReader.o src/main.cpp -o main

ParkingLot.o: src/Segment.h src/ParkingLot.h src/ParkingLot.cpp
	$(CC) $(FLAGS) src/ParkingLot.cpp -o ParkingLot.o

PlainTextReader.o: src/PlainTextReader.h src/PlainTextReader.cpp src/ISegmentReader.h src/Segment.h
	$(CC) $(FLAGS) src/PlainTextReader.cpp -o PlainTextReader.o

clean:
	rm src/*.o main

.PHONY:
	clean all
