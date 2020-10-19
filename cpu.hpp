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
    task (std::string n, int t, int p, int b) : name {n}, tid {t}, priority {p}, burst {b} {}
    ~task () {}

    void print (int slice) const {
        std::cout << "task = [" << name << "] [" << priority << "] [" << burst << "] for " << slice << " units.\n";
    }

private:
    std::string name;
    int tid;
    int priority;
    int burst; 
};

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