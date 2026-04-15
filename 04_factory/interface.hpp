#pragma once
#include "pch.hpp"

class IComponent
{
public:
    virtual ~IComponent()   = default;
    virtual int getDamage() = 0;
};

class IComponentFactory
{
public:
    virtual ~IComponentFactory()                = default;
    virtual unique_ptr<IComponent> makeScope()  = 0;
};