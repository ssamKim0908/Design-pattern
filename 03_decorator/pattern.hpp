#pragma once

#include "interface.hpp"
#include "pch.hpp"

class coffee : public IComponent
{
private:
    int coffeeCost = 5;
public:
    int cost() override;
};

class decorator : public IComponent
{
    //얘가 좀 거슬린다.
protected:
    shared_ptr<IComponent> wrapper;
public:
    decorator(shared_ptr<IComponent>&& wpp) : wrapper(wpp){};
    virtual int cost() = 0;
};

class sugar : public decorator
{
public:
    sugar(shared_ptr<IComponent>&& wpp) : decorator(move(wpp)) {};
    int cost() override;
};

class cream : public decorator
{
public:
    cream(shared_ptr<IComponent>&& wpp) : decorator(move(wpp)) {};
    int cost() override;
};

