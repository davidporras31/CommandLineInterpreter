#include "Command.h"

std::string Command::getName()
{
    return this->name;
}

void Command::setName(std::string name)
{
    if (this->name == "")
        this->name = name;
}

std::string Command::getHelp()
{
    return this->help;
}

void Command::setHelp(std::string help)
{
    this->help = help;
}