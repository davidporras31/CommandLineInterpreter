#include "HelpCommand.h"

HelpCommand::HelpCommand()
{
	this->setName("help");
	this->setHelp("help is a command which displays help for a given command");
	this->commands = nullptr;
}

std::string HelpCommand::execute(std::string args)
{
	std::string ret;
	bool found = false;
	if (!args.empty())
	{
		for (size_t i = 0; i < this->commands->size(); i++)
		{
			if (this->commands->at(i)->getName() == args)
			{
				ret = this->commands->at(i)->getHelp();
				found = true;
				break;
			}
		}
	}
	if (!found)
	{
		throw CommandNotFoundException(args);
	}
	return ret;
}
