/**
 * Implementation of Shortest-Job-First Scheduling.
 */

#include "CPU.hpp"

#include <set>

namespace cpu {

struct cpu_burst_compare {
    bool operator() (const class task &t1, const class task &t2) const {
        return t1.burst < t2.burst;
    }
};

class sjf_cpu : public CPU {
public:
    sjf_cpu (std::initializer_list<class task> l, int q) : task_list {l}, quantum {q}, duration {0} {}
    sjf_cpu (class task& t, int q) : task_list {t}, quantum {q}, duration {0} {}
    sjf_cpu (int q) : task_list {}, quantum {q}, duration {0} {}
    ~sjf_cpu () {}

    void insert (class task& t) override
    {
        task_list.insert (t);
    }

    void run () override
    {
        for (auto handle = task_list.extract (task_list.begin ()); !handle.empty ();
             handle = task_list.extract (task_list.begin ())) {
            auto shortest_job = handle.value ();
            shortest_job.set_wait (duration);
            shortest_job.print (1);
            duration += shortest_job.burst;
        }
    }

protected:
    std::multiset<class task, cpu_burst_compare> task_list;
    int quantum;
    int duration;
    int sum_wait;
};

} // namespace cpu