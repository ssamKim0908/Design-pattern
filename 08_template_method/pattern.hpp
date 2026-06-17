#pragma once
#include <vector>
#include "abstract.hpp"

class VectorIntWaitTemplateClass : public AWaitTemplateClass
{
public:
    VectorIntWaitTemplateClass();
    ~VectorIntWaitTemplateClass();

private:
    void wait           () override;
    void do_something   () override;
    bool exit           () override;

    void close          () override;
private:
    std::vector<int>     _vec;
    int                 _input;
    bool                _exit = true;
};
