/**
 * Implementation of Priority Scheduling.
 */

#include "CPU.hpp"

#include <unordered_map>
#include <deque>

namespace cpu {

class pri_cpu : public CPU {
public:
    pri_cpu (class task& t, int q) : CPU {q, 0, 0} {
        task_lists [t.get_priority()].push_back (t);
    }
    pri_cpu (int q) : task_lists {}, CPU {q, 0, 0} {}
    ~pri_cpu () {}

    void insert (class task& t) override
    {
        // TODO
    }

    class task* fetch_task () override
    {
        if (task_lists.empty ())
            return nullptr;
        
        for (int i = 1; i <= 10; i++) {
            if (task_lists[i].empty ())
                continue;
            
            auto t = &task_lists[i].front ();
            task_lists[i].pop_front ();
            return t;
        }

        return nullptr;
    }

    class task* process_one_task (class task* t) override
    {
        // TODO
        return nullptr;
    }

private:
    std::unordered_map<int, std::deque<class task>> task_lists;
};

} // namespace cpu