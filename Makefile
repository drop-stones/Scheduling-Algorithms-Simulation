
CXX=clang++
CXX_FLAGS= -std=c++17

SCHEDULE := schedule_fcfs schedule_sjf schedule_pri
SCHEDULE_HPP := $(SCHEDULE:%=%.hpp)

EXE := schedule_all

.PHONY: all clean

all: $(EXE)

schedule_all: CPU.hpp main.cpp $(SCHEDULE_HPP)
	$(CXX) $(CXX_FLAGS) -g -o schedule_all main.cpp

#schedule_fcfs: schedule_fcfs.hpp cpu.hpp main.cpp
#	$(CXX) -g -o schedule_fcfs main.cpp

clean:
	rm -rf $(EXE)