#ifndef CONSOLEH
#define CONSOLEH
#include <string>
#include <vector>
#include <exception>

#include "Command.h"
#include "CommandNotFoundException.h"
#include "CommandRuntimeException.h"

#include "HelpCommand.h"
#include "ListCommand.h"


class Console
{
public:
    Console();

    static void addBasicCommand(Console * console);

    void addCommand(Command* command);
    void removeCommand(size_t id);
    void removeCommand(std::string name);

    std::string commandeExecute(std::string buffer);

    std::string autoCompleteCommand(std::string buffer);
private:
    std::vector<Command*> commands;
    std::vector<Command*>* getCommands();
};

#endif // CONSOLEH