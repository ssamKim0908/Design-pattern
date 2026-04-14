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
    unique_ptr<IComponent> wrapper;
public:
    decorator(unique_ptr<IComponent>&& wpp) : wrapper(move(wpp)){};
    virtual int cost() = 0;
};

class sugar : public decorator
{
public:
    sugar(unique_ptr<IComponent>&& wpp) : decorator(move(wpp)) {};
    int cost() override;
};

class cream : public decorator
{
public:
    cream(unique_ptr<IComponent>&& wpp) : decorator(move(wpp)) {};
    int cost() override;
};

