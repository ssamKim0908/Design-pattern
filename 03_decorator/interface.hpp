#pragma once

class IComponent
{
public:
    virtual ~IComponent()   = default;
    virtual int cost()      = 0;
};