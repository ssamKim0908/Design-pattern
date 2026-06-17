#include <iostream>
#include <algorithm>
#include "pattern.hpp"

/*******private*******/
void VectorIntWaitTemplateClass::wait ()
{
    std::cin >> _input;
}
void VectorIntWaitTemplateClass::do_something()
{
    switch (_input)
    {
    case 0:
    {
        int insert_value;
        std::cin >> insert_value;
        //여기 type 검사 필요

        _vec.emplace_back(insert_value);
        break;
    }
    case 1:
    {
        sort(_vec.begin(),_vec.end());
        break;
    }
    case 2:
    {
        for(auto cur : _vec) {std::cout << cur << ' ';}
        std::cout << std::endl;
        break;
    }
    case 3:
    {
        _exit = false;
        break;
    }
    default:
    {
        std::cout << "Invaild Arguement\n";        
    }
    
    }
}
bool VectorIntWaitTemplateClass::exit()
{
    return _exit;
}
void VectorIntWaitTemplateClass::close()
{
    for(auto cur : _vec) {std::cout << cur << ' ';}
    std::cout << "Have a good night" <<std::endl;
}

/*******public*******/
VectorIntWaitTemplateClass::VectorIntWaitTemplateClass() = default;
VectorIntWaitTemplateClass::~VectorIntWaitTemplateClass() = default;
