#pragma once
#include "interface.hpp"
#include <thread>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <atomic>

struct FCustomDeleter
{
    void operator()(sem_t *sema) const
    {
        if (sema != nullptr)
        {
            sem_close(sema);
        }
    }
};

class ObserverThread : public enable_shared_from_this<ObserverThread>, public IObserver
{

private:
    using UniqueSemaCustomDeleter = unique_ptr<sem_t, FCustomDeleter>;

    int num;
    thread t;
    UniqueSemaCustomDeleter sema;
    atomic<bool> finish{false};

public:
    ObserverThread(const string &&str, int number);

    ObserverThread(const ObserverThread &obj)               = delete;
    ObserverThread &operator=(const ObserverThread &obj)    = delete;

    ObserverThread(const ObserverThread &&obj)              = delete;
    ObserverThread &operator=(const ObserverThread &&obj)   = delete;

    void wait();
    void post();

    void startThread();

    void update(int newNum) override;

    void setTrue() { finish = true; }
    bool getTrue() { return finish; }

    virtual void threadImpl() = 0;
    int getNum() { return num; }

    ~ObserverThread();
};

class ObserverThreadFirstClassImpl : public ObserverThread
{
public:
    ObserverThreadFirstClassImpl(const string &&str, int number) : ObserverThread(move(str), number) {};
    void threadImpl() override;
};

class ObserverThreadSecondClassImpl : public ObserverThread
{
public:
    ObserverThreadSecondClassImpl(const string &&str, int number) : ObserverThread(move(str), number) {};
    void threadImpl() override;
};

class ObserverThreadThirdClassImpl : public ObserverThread
{

public:
    ObserverThreadThirdClassImpl(const string &&str, int number) : ObserverThread(move(str), number) {};
    void threadImpl() override;
};