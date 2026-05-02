#pragma once
#include <queue>
#include <mutex>
#include <thread>
#include <vector>
#include <memory>
#include <condition_variable>
#include "interface.hpp"

class SimpleThreadPool
{
private:
    std::queue<std::shared_ptr<ICommand>>   iqueue;
    std::vector<std::thread>                v_thread;
    std::mutex                              mtx;
    std::condition_variable                 cv;
    bool                                    is_finish = false;
private:
    void _thread();
public:
    SimpleThreadPool(int num);

    void add_queue(const std::shared_ptr<ICommand>& psh);
    void finsih();

    ~SimpleThreadPool();
};