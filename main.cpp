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
    if (argc < 2) {
        std::cout << "Usage: " << argv [0] << " <scheduling algorithm name>\n";
        exit (1);
    }

    std::cout << "Schedule : " << argv [1] << '\n';
    fcfs_cpu fcfs {10};

    std::ifstream ifs ("./processes.txt");
    char buf [1024];
    for (int i = 0; ifs.getline (buf, 1024); i++) {
        char name [10], priority [10], burst [10];
        std::stringstream ss {buf};
        ss.getline (name, 10, ',');
        ss.getline (priority, 10, ',');
        ss.getline (burst, 10);
        std::string n {name};
        int p = atoi (priority);
        int b = atoi (burst);
        class task t { n, i, p, b};
        fcfs.insert (t);
    }

    fcfs.run ();
}