
CXX=clang++
CXX_FLAGS= -std=c++17

SCHEDULES := fcfs pri #sjf
TESTS := $(SCHEDULES:%=%_test)

.PHONY: all clean

all: $(TESTS)

fcfs_test: fcfs_test.cpp ../CPU.hpp ../schedule_fcfs.hpp 
	$(CXX) $(CXX_FLAGS) -g -o fcfs_test fcfs_test.cpp

pri_test: pri_test.cpp ../CPU.hpp ../schedule_pri.hpp
	$(CXX) $(CXX_FLAGS) -g -o pri_test pri_test.cpp

clean:
	rm -rf $(TESTS)