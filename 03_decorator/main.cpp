#include "../pch.hpp"
#include "pattern.hpp"

int main() 
{
    shared_ptr<IComponent> cff = make_shared<coffee>();
    shared_ptr<IComponent> cffWithSugar = make_shared<sugar>(move(cff));
    shared_ptr<IComponent> cffWithSugarAndCream = make_shared<cream>(move(cffWithSugar));

    cout << cffWithSugarAndCream->cost() << endl;

    return 0;
}