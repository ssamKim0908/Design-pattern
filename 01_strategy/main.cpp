#include "../common_header.hpp"
#include "pattern.hpp"
#include "interface.hpp"

int main() 
{
    shared_ptr<IStrategyCalculator> sPlus    = make_shared<Plus>();
    shared_ptr<IStrategyCalculator> sMinus   = make_shared<Minus>();
    shared_ptr<IStrategyCalculator> sProduct = make_shared<Product>();

    Context context;
    int strategy, a, b;
    while(1)
    {
        cout << "0 : Exit" << endl;
        cout << "1 : Plus" << endl;
        cout << "2 : Minus" << endl;
        cout << "3 : Product" << endl;

        cin >> strategy;
        if(strategy == 0) break;

        switch (strategy)
        {
        case 1 :
            context.setCalculation(sPlus);
            break;
        case 2 :
            context.setCalculation(sMinus);
            break;
        case 3 :
            context.setCalculation(sProduct);
            break;
        default:
            context.setCalculation(nullptr);
            break;
        }
        
        cin >> a >> b;
        cout << "Result : ";
        cout << context.calculate(a, b) << endl;
    }
    return 0;
}