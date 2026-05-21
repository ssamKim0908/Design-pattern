#include "../common_header.hpp"
#include "pattern.hpp"

#include <fstream>

int main() 
{
    RVectorI32 r_vec;

    r_vec.push_back(3323);
    r_vec.push_back(112);
    r_vec.push_back(225);
    r_vec.push_back(886487);

    auto cout_r_vec = [&r_vec]()
    {
        for(int i = 0; i < r_vec.size(); i++)
        {
            cout << r_vec[i] << ' ';
        }
        cout << endl;
    };

    cout_r_vec();

    sort(r_vec.begin(), r_vec.end());
    
    cout_r_vec();
    return 0;
}