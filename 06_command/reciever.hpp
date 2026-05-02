#pragma once
#include <mutex>

class RecvCount
{
private:
    int count = 0;
    std::mutex mtx;
public:
    void add_count();
    void minus_count();
};

class RecvPrint
{
private:
    std::mutex mtx;
public:
    void print_excute();
    void print_undo();
};