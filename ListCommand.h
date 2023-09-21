#ifndef LISTCOMMANDH
#define LISTCOMMANDH
#include <vector>

#include "Command.h"

class ListCommand :
    public Command
{
public:
    std::vector<Command*>* commands;

    ListCommand();
    // Hérité via Command
    virtual std::string execute(std::string args) override;
};

#endif // LISTCOMMANDH