// test for fcfs scheduling

#include <cassert>
#include <fstream>
#include "../schedule_fcfs.hpp"

using namespace cpu;

int main (void)
{
    // initialize fcfs_cpu
    fcfs_cpu fcfs {10};
    // receive tasks
    std::ifstream ifs ("../processes.txt");
    if (!ifs) {
        std::cerr << "Cannot open the file! \"processes.txt\"\n";
        exit (1);
    }
    for (class task t {}; ifs >> t;) {
        fcfs.insert (t);
    }

    // Test for proper order
    auto task_list = fcfs.get_task_list ();
    assert (task_list[0].get_name() == "P1");
    assert (task_list[1].get_name() == "P2");
    assert (task_list[2].get_name() == "P3");
    assert (task_list[3].get_name() == "P4");
    assert (task_list[4].get_name() == "P5");

    std::cout << "Test pass!\n";
}