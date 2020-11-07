// test for cpu::pri_cpu class

#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include "../schedule_pri.hpp"

TEST_GROUP(PriTestGroup){};

// Test for insert()

// Test for fetch_task()
TEST(PriTestGroup, FetchTask)
{
    cpu::task t {"P1", 1, 4, 5};
    cpu::pri_cpu pri {t, 10};

    cpu::task tsk = pri.fetch_task ();
    STRCMP_EQUAL (tsk.get_name().c_str(), "P1");
}

// Test for process_one_task()

int main (int argc, char *argv [])
{
    return CommandLineTestRunner::RunAllTests (argc, argv);
}