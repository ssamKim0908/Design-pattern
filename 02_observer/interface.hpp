#pragma once
#include "../common_header.hpp"

class IObserver
{
    public:
    virtual void update(int newNum)     = 0;
    virtual ~IObserver()                = default;
};

class ISubject
{
public:
    virtual void registerObserver   (const shared_ptr<IObserver> obj)    = 0;
    virtual void notifyObservers    (int number)                         = 0;

    virtual ~ISubject()             = default;
};