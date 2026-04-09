#pragma once

class IStrategyCalculator
{
public:
    virtual int calculate(int a, int b) = 0;
    virtual ~IStrategyCalculator()      = default;
};