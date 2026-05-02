#include "reciever.hpp"
#include <iostream>

void RecvCount::add_count()
{
    std::lock_guard<std::mutex> lock(mtx);
    if(count < 10)
    {
        count++;
    }
    std::cout << "Count Add : " << count << std::endl;
}

void RecvCount::minus_count()
{
    std::lock_guard<std::mutex> lock(mtx);
    if(count > 0)
    {
        count--;
    }
    std::cout << "Count Minus : " << count << std::endl;
}

void RecvPrint::print_excute()
{
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Recv Print Call" << std::endl;
}

void RecvPrint::print_undo()
{
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Recv undo Call" << std::endl;
}
