#include "ListCommand.h"

ListCommand::ListCommand()
{
	this->commands = nullptr;
	this->setName("list");
	this->setHelp("list all command loaded");
}

std::string ListCommand::execute(std::string args)
{
	std::string ret;
	for (size_t i = 0; i < this->commands->size(); i++)
	{
		ret.append( this->commands->at(i)->getName() + "\n");
	}
	return ret;
}
