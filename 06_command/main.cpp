#include "../common_header.hpp"
#include "invoker.hpp"
#include "command.hpp"
#include "reciever.hpp"
#include <chrono>
#include <thread>

int main()
{
    SimpleThreadPool s_thread{3};

    std::shared_ptr<pImpCommandCountExcute> count = pImpFactory::make_count();
    std::shared_ptr<pImpCommandPrintExcute> print = pImpFactory::make_print();

    //여기도 뭔가 팩토리로 빼면 참 좋을 것 같다.
    std::shared_ptr<CommandCountExecute>    c_count_ex      = std::make_shared<CommandCountExecute>(count);
    std::shared_ptr<CommandCountUndo>       c_count_undo    = std::make_shared<CommandCountUndo>(count);

    std::shared_ptr<CommandPrintExecute>    c_print_ex      = std::make_shared<CommandPrintExecute>(print);
    std::shared_ptr<CommandPrintUndo>       c_print_undo    = std::make_shared<CommandPrintUndo>(print);

    s_thread.add_queue(c_count_ex);
    s_thread.add_queue(c_count_ex);
    s_thread.add_queue(c_count_undo);
    s_thread.add_queue(c_count_ex);
    s_thread.add_queue(c_count_undo);

    s_thread.add_queue(c_print_ex);
    s_thread.add_queue(c_print_ex);
    s_thread.add_queue(c_print_undo);
    s_thread.add_queue(c_print_ex);
    s_thread.add_queue(c_print_undo);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    s_thread.finsih();
    return 0;
}