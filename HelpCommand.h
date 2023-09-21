#ifndef HELPCOMMANDH
#define HELPCOMMANDH
#include <vector>

#include "Command.h"
#include "CommandNotFoundException.h"

class HelpCommand :
    public Command
{
public:
    std::vector<Command*>* commands;

    HelpCommand();
    // Hérité via Command
    virtual std::string execute(std::string args) override;
};

#endif // HELPCOMMANDH