/**
 * Implementation of First-Come First-Served Scheduling.
 */

#include "CPU.hpp"

#include <deque>

namespace cpu {

class fcfs_cpu : public CPU {
public:
    fcfs_cpu (std::initializer_list<class task> l, int q) : task_list {l}, quantum {q}, duration {0} {}
    fcfs_cpu (class task& t, int q) : task_list {std::deque<class task> (1, t)}, quantum {q}, duration {0} {}
    fcfs_cpu (int q) : task_list {}, quantum {q}, duration {0} {}
    ~fcfs_cpu () {}

    void insert (class task& t) override
    {
        task_list.push_back (t);
    }

    void run () override
    {
        for (auto t = task_list.front (); !task_list.empty (); t = task_list.front ()) {
            t.set_wait (duration);
            t.print (1);
            duration += t.burst;
            task_list.pop_front ();
        }
    }

protected:
    std::deque<class task> task_list;
    int quantum;
    int duration;
    int sum_wait;
};

} // namespace cpu