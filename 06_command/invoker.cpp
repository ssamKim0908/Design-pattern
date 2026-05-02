#include "invoker.hpp"

//----------------private-----------------
void SimpleThreadPool::_thread()
{
    while(true)
    {
        std::shared_ptr<ICommand> cmd;
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, 
                [this]()
            {
                return !iqueue.empty() || is_finish;
            });

            if(is_finish) return;

            cmd = std::move(iqueue.front());
            iqueue.pop();
        }
        cmd->execute();
    }
}

//--------------public-------------------
SimpleThreadPool::SimpleThreadPool(int num)
{
    for(int i = 0; i < num; i++)
    {
        v_thread.push_back(std::thread(&SimpleThreadPool::_thread, this));
    }
}

void SimpleThreadPool::add_queue(const std::shared_ptr<ICommand>& psh)
{
    {
        std::lock_guard<std::mutex> lock(mtx);
        iqueue.push(psh);
    }
    cv.notify_one();
}

void SimpleThreadPool::finsih()
{
    {
        std::lock_guard<std::mutex> lock(mtx);
        is_finish = true;
    }
    cv.notify_all();
}

SimpleThreadPool::~SimpleThreadPool()
{
    for(auto& _th : v_thread)
    {
        if(_th.joinable())
        {
            _th.join();
        }
    }
}