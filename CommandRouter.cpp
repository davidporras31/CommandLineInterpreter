#include "CommandRouter.h"

std::string CommandLineInterpreter::execute(std::string args)
{
    std::string ret;
    bool use = false;
    size_t first_delimitor = args.find_first_of(' ');
    std::string command_name = args;
    std::string new_args;
    if (first_delimitor != std::string::npos)
    {
        command_name = args.substr(0, first_delimitor);
        new_args = args.substr(first_delimitor + 1);
    }

    for (size_t i = 0; i < this->commands.size(); i++)
    {
        if (this->commands.at(i)->getName() == command_name)
        {
            try
            {
                ret = this->commands.at(i)->execute(new_args);
            }
            catch (std::exception e)
            {
                throw CommandRuntimeException(this->commands.at(i)->getName(), e.what());
            }
            catch (...)
            {
                throw CommandRuntimeException(this->commands.at(i)->getName(), "unknown");
            }
            use = true;
            break;
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
