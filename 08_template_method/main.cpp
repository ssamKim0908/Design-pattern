#include "../common_header.hpp"
#include "pattern.hpp"
#include "abstract.hpp"

int main() 
{
    std::unique_ptr<AWaitTemplateClass> pattern = make_unique<VectorIntWaitTemplateClass>();
    pattern->run();
    return 0;
}