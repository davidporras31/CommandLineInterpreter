#include "CommandRouter.h"

std::string CommandLineInterpreter::execute(std::string args)
{
    bool use = false;
    for (size_t i = 0; i < this->commands.size(); i++)
    {
        std::string com_name = this->commands.at(i)->getName();
        if (args.size() >= com_name.size())
        {
            char deli = ',';
            if (args.size() > com_name.size())
                deli = args[com_name.size()];
            if (com_name == args.substr(0, com_name.size()))
            {
                if (args.size() == com_name.size() || (args.size() > com_name.size() && deli == ' '))
                {
                    std::string next_args = "";
                    if (args.size() > com_name.size())
                        next_args = args.substr(com_name.size() + 1);
                    this->commands.at(i)->execute(next_args);
                    use = true;
                    break;
                }
            }
        }
    }
    if (!use)
    {
        throw CommandNotFoundException(this->getName() + "." + args);
    }
}

void CommandLineInterpreter::add(Command* command)
{
	this->commands.push_back(command);
}

std::vector<Command*>* CommandLineInterpreter::getRoutes()
{
    return &this->commands;
}
