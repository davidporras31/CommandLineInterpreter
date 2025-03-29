#include "Console.h"

Console::Console()
{
}

void Console::addBasicCommand(Console* console)
{

    ListCommand* listCommand = new ListCommand();
    listCommand->commands = console->getCommands();
    console->addCommand(listCommand);

    HelpCommand* helpCommand = new HelpCommand();
    helpCommand->commands = console->getCommands();
    console->addCommand(helpCommand);
    
}


std::string Console::commandeExecute(std::string buffer)
{
    std::string ret;
    bool use = false;
    size_t first_delimitor = buffer.find_first_of(' ');
    std::string command_name = buffer;
    std::string args = "";
    if (first_delimitor != std::string::npos)
    {
        command_name = buffer.substr(0, first_delimitor);
        args = buffer.substr(first_delimitor + 1);
    }

    for (size_t i = 0; i < this->commands.size(); i++)
    {
        if( this->commands.at(i)->getName() == command_name)
        {
            try 
            {
                ret = this->commands.at(i)->execute(args);
            }catch(CommandNotFoundException e)
            {
                throw CommandRuntimeException(this->commands.at(i)->getName(), e.what());
            }catch(CommandRuntimeException e)
            {
                throw CommandRuntimeException(this->commands.at(i)->getName(), e.what());
            }catch(std::exception e)
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
        throw CommandNotFoundException(buffer);
    }
    return ret;
}

std::string Console::autoCompleteCommand(std::string buffer)
{
    std::string ret; 
    for (size_t i = 0; i < this->commands.size(); i++)
    {
        if (this->commands.at(i)->getName().find_first_of(buffer) == 0u)
        {
            ret = this->commands.at(i)->getName();
            break;
        }
    }
    return ret;
}

void Console::addCommand(Command* command)
{
    this->commands.push_back(command);
}

void Console::removeCommand(size_t id)
{
    delete this->commands.at(id);
    this->commands.erase(this->commands.begin() + id);
}

void Console::removeCommand(std::string name)
{
    size_t id = SIZE_MAX;
    for (size_t i = 0; i < this->commands.size(); i++)
    {
        if (this->commands.at(i)->getName() == name)
        {
            id = i;
            break;
        }
    }
    if (id != SIZE_MAX)
        this->removeCommand(id);
}

std::vector<Command*>* Console::getCommands()
{
    return &this->commands;
}
