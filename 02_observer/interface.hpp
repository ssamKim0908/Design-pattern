#pragma once
#include "../pch.hpp"

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
    virtual void removeObserver     (const weak_ptr<IObserver> obj)      = 0;
    virtual void notifyObservers    (int number)                         = 0;

    virtual ~ISubject()             = default;
};