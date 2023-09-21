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
    for (size_t i = 0; i < this->commands.size(); i++)
    {
        std::string com_name = this->commands.at(i)->getName();
        if (buffer.size() >= com_name.size())
        {
            char deli = ',';
            if (buffer.size() > com_name.size())
                deli = buffer[com_name.size()];
            if (com_name == buffer.substr(0, com_name.size()))
            {
                if (buffer.size() == com_name.size() || (buffer.size() > com_name.size() && deli == ' '))
                {
                    std::string args = "";
                    if (buffer.size() > com_name.size())
                        args = buffer.substr(com_name.size() + 1);
                    try 
                    {
                        ret = this->commands.at(i)->execute(args);
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
