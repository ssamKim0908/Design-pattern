#include "observer.hpp"

ObserverThread::ObserverThread(const string &&str, int number)
{
    sem_unlink(str.c_str());
    sema = UniqueSemaCustomDeleter(sem_open(str.c_str(), O_CREAT, 0666, 0));
    
    if (sema.get() == SEM_FAILED)
    {
        throw std::runtime_error("세마 실패");
    }

    num = number;
}

void ObserverThread::wait()
{
    sem_wait(sema.get());
}

void ObserverThread::post()
{
    sem_post(sema.get());
}

void ObserverThread::startThread()
{
    startThreadImpl();
};

void ObserverThread::update(int newNum)
{
    num = newNum;
    post();
}

//First
void ObserverThreadFirstClassImpl::startThreadImpl()
{
    t = std::thread(&ObserverThread::threadImpl, shared_from_this());
}

ObserverThreadFirstClassImpl::~ObserverThreadFirstClassImpl()
{
    setTrue();
    post();
    if (t.joinable())
    {
        t.join();
    }
}

void ObserverThreadFirstClassImpl::threadImpl()
{
    while(!getTrue())
    {
        wait();
        cout << "First: This number is " << this->getNum() << endl;
    }
}

//Second
void ObserverThreadSecondClassImpl::startThreadImpl()
{
    t = std::thread(&ObserverThread::threadImpl, shared_from_this());
}

ObserverThreadSecondClassImpl::~ObserverThreadSecondClassImpl()
{
    setTrue();
    post();
    if (t.joinable())
    {
        t.join();
    }
}

void ObserverThreadSecondClassImpl::threadImpl()
{
    while(!getTrue())
    {
        wait();
        cout << "Second: This number is " << this->getNum() * 2<< endl;
    }
}


//Third
void ObserverThreadThirdClassImpl::startThreadImpl()
{
    t = std::thread(&ObserverThread::threadImpl, shared_from_this());
}

ObserverThreadThirdClassImpl::~ObserverThreadThirdClassImpl()
{
    setTrue();
    post();
    if (t.joinable())
    {
        t.join();
    }
}

void ObserverThreadThirdClassImpl::threadImpl()
{
    while(!getTrue())
    {
        wait();
        cout << "Third: This number is " << this->getNum() * 3 << endl;
    }
}