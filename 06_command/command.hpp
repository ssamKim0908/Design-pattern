#pragma once
#include "interface.hpp"
#include <memory>

struct pImpCommandCountExcute;
struct pImpCommandPrintExcute;

namespace pImpFactory
{
    std::shared_ptr<pImpCommandCountExcute> make_count();
    std::shared_ptr<pImpCommandPrintExcute> make_print();
}

class CommandCountExecute : public ICommand
{
private:
    std::shared_ptr<pImpCommandCountExcute> recv;
public:
    CommandCountExecute(const std::shared_ptr<pImpCommandCountExcute>&);
    ~CommandCountExecute();

    void execute();
};

class CommandCountUndo : public ICommand
{
private:
    std::shared_ptr<pImpCommandCountExcute> recv;
public:
    CommandCountUndo(const std::shared_ptr<pImpCommandCountExcute>&);
    ~CommandCountUndo();

    void execute();
};


class CommandPrintExecute : public ICommand
{
private:
    std::shared_ptr<pImpCommandPrintExcute> recv;
public:
    CommandPrintExecute(const std::shared_ptr<pImpCommandPrintExcute>&);
    ~CommandPrintExecute();

    void execute();
};

class CommandPrintUndo : public ICommand
{
private:
    std::shared_ptr<pImpCommandPrintExcute> recv;
public:
    CommandPrintUndo(const std::shared_ptr<pImpCommandPrintExcute>&);
    ~CommandPrintUndo();

    void execute();
};