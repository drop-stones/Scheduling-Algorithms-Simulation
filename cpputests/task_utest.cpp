// test for cpu::task class

#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include "../CPU.hpp"

TEST_GROUP(TaskTestGroup){};

// Test for cpu::task.get_name()
TEST(TaskTestGroup, GetNameTest)
{
    cpu::task t {"P1", 1, 4, 5};
    STRCMP_EQUAL (t.get_name().c_str(), "P1");
}

// Test for cpu::task.get_burst()
TEST(TaskTestGroup, GetBurstTest)
{
    cpu::task t {"P1", 1, 4, 5};
    CHECK_EQUAL (t.get_burst(), 5);
}

int main (int argc, char *argv [])
{
    return CommandLineTestRunner::RunAllTests (argc, argv);
}