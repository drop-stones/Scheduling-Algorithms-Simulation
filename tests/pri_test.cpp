// test for fcfs scheduling

#include <cassert>
#include <fstream>
#include "../schedule_pri.hpp"

using namespace cpu;

// Unit-test for fetch_task ()
void FetchTaskTest ()
{
    task t {"P1", 1, 4, 5};
    pri_cpu pri {t, 10};

    auto tsk = pri.fetch_task ();
    assert (tsk != nullptr);
    assert (tsk->get_name() == "P1");
}

int main (void)
{
    FetchTaskTest ();

    std::cout << "Test pass!\n";
}