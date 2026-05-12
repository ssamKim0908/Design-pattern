#include "../common_header.hpp"
#include "pattern.hpp"

int main() 
{
    unique_ptr<IComponent> cff = make_unique<coffee>();
    unique_ptr<IComponent> cffWithSugar = make_unique<sugar>(move(cff));
    unique_ptr<IComponent> cffWithSugarAndCream = make_unique<cream>(move(cffWithSugar));

    cout << cffWithSugarAndCream->cost() << endl;

    return 0;
}