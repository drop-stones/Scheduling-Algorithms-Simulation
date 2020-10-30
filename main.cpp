/**
 * main function.
 * Please select scheduling algorithms by giving name.
 */

#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "schedule_fcfs.hpp"

int main (int argc, char *argv [])
{
    /*
    if (argc < 2) {
        std::cout << "Usage: " << argv [0] << " <scheduling algorithm name>\n";
        exit (1);
    }
    */

    std::cout << "Schedule : " << "fcfs" << '\n';
    fcfs_cpu fcfs {10};

    std::ifstream ifs ("./processes.txt");
    char buf [1024];
    for (class task t {}; ifs >> t;)
        fcfs.insert (t);

    fcfs.run ();
}