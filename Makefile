
CXX=clang++

.PHONY: all clean

all: schedule_fcfs

schedule_fcfs: schedule_fcfs.hpp cpu.hpp main.cpp
	$(CXX) -o schedule_fcfs main.cpp

clean:
	rm -rf schedule_fcfs