/**
 * Implementation of Shortest-Job-First Scheduling.
 */

#include "CPU.hpp"

#include <deque>
#include <algorithm>

namespace cpu {

// burst-time order
bool operator< (const class task &t1, const class task &t2) {
    return t1.get_burst () < t2.get_burst ();
}

bool operator> (const class task &t1, const class task &t2) {
    return t1.get_burst () > t2.get_burst ();
}

class sjf_cpu : public CPU {
public:
    sjf_cpu (std::initializer_list<class task> l, int q) : task_list {l}, quantum {q}, duration {0} {}
    sjf_cpu (class task& t, int q) : task_list {t}, quantum {q}, duration {0} {}
    sjf_cpu (int q) : task_list {}, quantum {q}, duration {0} {}
    ~sjf_cpu () {}

    void insert (class task& t) override
    {
        task_list.push_back (t);
        std::sort (task_list.begin (), task_list.end ());
    }

    class task* fetch_task () override
    {
        if (task_list.empty ())
            return nullptr;
        
        auto t = &task_list.front ();
        task_list.pop_front ();
        return t;
    }

    void run () override
    {
        for (auto t = fetch_task (); t != nullptr; t = fetch_task ()) {
            t->set_wait (duration);
            t->print (1);
            duration += t->get_burst ();
        }
    }

private:
    std::deque<class task> task_list;
    int quantum;
    int duration;
    int sum_wait;
};

} // namespace cpu