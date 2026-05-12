#pragma once
#include "interface.hpp"
#include "../common_header.hpp"

//context
class Context
{
private:
    shared_ptr<IStrategyCalculator> calculation = nullptr;
public:
    Context() = default;

    Context(const Context& PCalculation)            = default;
    Context& operator=(const Context& PCalculation) = default;

    Context(Context&& PCalculation)                 = default;
    Context& operator=(Context&& PCalculation)      = default;

    ~Context()                                      = default;

    void setCalculation(const shared_ptr<IStrategyCalculator>& PCalculation)
    {
        calculation = PCalculation;
    }

    int calculate(int a, int b)
    {
        if(calculation == nullptr) return -123456789;
        return calculation->calculate(a, b);
    }
};

//concrete class
class Plus : public IStrategyCalculator
{
public:
    int calculate(int a, int b) override;
};

class Minus : public IStrategyCalculator
{
public:
    int calculate(int a, int b) override;
};

class Product : public IStrategyCalculator
{
public:
    int calculate(int a, int b) override;
};