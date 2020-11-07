/**
 * Implementation of First-Come First-Served Scheduling.
 */

#include "CPU.hpp"

#include <deque>

namespace cpu {

class fcfs_cpu : public CPU {
public:
    fcfs_cpu (std::initializer_list<class task> l, int q) : task_list {l}, CPU {q, 0, 0} {}
    fcfs_cpu (class task& t, int q) : task_list {std::deque<class task> (1, t)}, CPU {q, 0, 0} {}
    fcfs_cpu (int q) : task_list {}, CPU {q, 0, 0} {}
    ~fcfs_cpu () {}

    void insert (class task& t) override
    {
        task_list.push_back (t);
    }

    class task* fetch_task () override
    {
        if (task_list.empty ())
            return nullptr;
            
        auto t = &task_list.front ();
        task_list.pop_front ();
        return t;
    }

    class task* process_one_task (class task* t) override
    {
        if (t == nullptr)
            return nullptr;
        
        t->set_wait (duration);
        t->print (1);
        duration += t->get_burst ();
        return t;
    }

    std::deque<class task> get_task_list ()
    {
        return task_list;
    }


private:
    std::deque<class task> task_list;
};

} // namespace cpu