#include "abstract.hpp"

/*****************private*****************/
void AWaitTemplateClass::close  () {};

/******public*****/
AWaitTemplateClass::AWaitTemplateClass  () = default;
AWaitTemplateClass::~AWaitTemplateClass () = default;

void AWaitTemplateClass::run()
{
    while(exit())
    {
        wait();
        do_something();
    }
    close();
}

