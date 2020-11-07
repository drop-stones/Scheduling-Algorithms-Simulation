/**
 * Virtual cpu
 */

#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <string>

namespace cpu {

enum class schedule_kind { fcfs, sjf, rr, priority, priority_rr };

class task {
public:
    task (std::string n, int t, int p, int b) : name {n}, tid {t}, priority {p}, burst {b}, wait {0} {}
    task () : tid {0}, priority {0}, burst {0}, wait {0} {}
    ~task () {}

    void set (std::string n, int p, int b) {
        name = n;
        priority = p;
        burst = b;
    }

    void set_wait (int w) {
        wait = w;
    }

    int get_burst () const {
        return burst;
    }

    void print (int slice) const {
        std::cout << wait << " wait: " << "task { name:" << name << ", priority:" << priority << ", burst:" << burst << " } for " << slice << " units.\n";
    }

private:
    std::string name;
    int tid;
    int priority;
    int burst;
    int wait;
};

std::ostream& operator<< (std::ostream& os, const task& t)
{
    // return os << "task = [" << t.name << "] [" << t.priority << "] [" << t.burst << "]\n";
    t.print (1);
    return os;
}

std::istream& operator>> (std::istream& is, task& t)
{
    char c;
    std::string name;
    int priority, burst;
    while (is >> c && c != ',')
        name += c;
    is >> priority;
    is >> c;
    is >> burst;
    t.set (name, priority, burst);
    return is;
}

class CPU {
public:
    CPU (int q, int d, int s) : quantum {q}, duration {d}, sum_wait {s} {}
    virtual ~CPU () {}

    virtual void insert (class task& t) = 0;
    virtual class task* fetch_task () = 0;
    virtual class task* process_one_task (class task* t) = 0;
    
    void run () {
        for (task* t = fetch_task (); t != nullptr; t = fetch_task ()) {
            process_one_task (t);
        }
    }

protected:
    int quantum;
    int duration;
    int sum_wait;
};

} // namespace cpu

#endif