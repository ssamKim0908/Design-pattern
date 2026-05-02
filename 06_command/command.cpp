#include "command.hpp"
#include "reciever.hpp"

struct pImpCommandCountExcute
{
    RecvCount impl;
};

struct pImpCommandPrintExcute
{
    RecvPrint impl;
};

namespace pImpFactory
{
    std::shared_ptr<pImpCommandCountExcute> make_count()
    {
        return std::make_shared<pImpCommandCountExcute>();
    }
    
    std::shared_ptr<pImpCommandPrintExcute> make_print()
    {
        return std::make_shared<pImpCommandPrintExcute>();
    }
}

CommandCountExecute::CommandCountExecute(const std::shared_ptr<pImpCommandCountExcute>& p_recv)
{
    recv = p_recv;
}

CommandCountUndo::CommandCountUndo(const std::shared_ptr<pImpCommandCountExcute>& p_recv)
{
    recv = p_recv;
}


CommandPrintExecute::CommandPrintExecute(const std::shared_ptr<pImpCommandPrintExcute>& p_recv)
{
    recv = p_recv;
}


CommandPrintUndo::CommandPrintUndo(const std::shared_ptr<pImpCommandPrintExcute>& p_recv)
{
    recv = p_recv;
}

CommandCountExecute::~CommandCountExecute()   = default;
CommandCountUndo::~CommandCountUndo()       = default;
CommandPrintExecute::~CommandPrintExecute()   = default;
CommandPrintUndo::~CommandPrintUndo()       = default;

// Count execute
void CommandCountExecute::execute()
{
    recv->impl.add_count();
}

//Count Undo
void CommandCountUndo::execute()
{
    recv->impl.minus_count();
}

//Print Execute
void CommandPrintExecute::execute()
{
    recv->impl.print_excute();
}

//Print Undo
void CommandPrintUndo::execute()
{
    recv->impl.print_undo();
}
