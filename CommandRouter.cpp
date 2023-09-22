#include "CommandRouter.h"

std::string CommandRouter::execute(std::string args)
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
    return ret;
}

std::string CommandRouter::getHelp()
{
    std::string ret = "";
    ret.append(Command::getHelp() + "\n");
    ret.append(std::string("subcommand:") + "\n");
    for (size_t i = 0; i < this->commands.size(); i++)
    {
        ret.append(this->commands.at(i)->getName() + "\n");
    }
    return ret;
}

void CommandRouter::add(Command* command)
{
	this->commands.push_back(command);
}

std::vector<Command*>* CommandRouter::getRoutes()
{
    return &this->commands;
}
