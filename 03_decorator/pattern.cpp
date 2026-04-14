#include "pattern.hpp"

int coffee::cost()
{
    cout << "coffee cost" << endl;
    return coffeeCost;
}

int sugar::cost()
{
    cout << "sugar cost" << endl;
    return 2 + wrapper->cost();
}

int cream::cost()
{
    cout << "cream cost" << endl;
    return 3 + wrapper->cost();
}