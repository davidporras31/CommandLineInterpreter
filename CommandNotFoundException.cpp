#include "CommandNotFoundException.h"

CommandNotFoundException::CommandNotFoundException(std::string message)
{
	this->message = message;
}
const char* CommandNotFoundException::what() const throw()
{
    return (new std::string("command " + message + " not found"))->c_str();
}
