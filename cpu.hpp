/**
 * Virtual cpu
 */

#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <deque>
#include <string>

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

    void set_wait (int w)
    {
        wait = w;
    }

    void print (int slice) const {
        std::cout << wait << " wait: " << "task { name:" << name << ", priority:" << priority << ", burst:" << burst << " } for " << slice << " units.\n";
    }

public:
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

class cpu {
public:
    //cpu (std::initializer_list<class task> l, int q) : task_list {l}, quantum {q} {}
    //cpu (class task& t, int q) : task_list {std::deque<class task> (1, t)}, quantum {q} {}
    virtual ~cpu () {}

    // virtual functions
    virtual void insert (class task& t) = 0;
    virtual void run () = 0;
};

#endif