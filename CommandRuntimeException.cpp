#include "CommandRuntimeException.h"

CommandRuntimeException::CommandRuntimeException(std::string message,  std::string exception)
{
	this->message = message;
	this->exception = exception;
}
const char* CommandRuntimeException::what() const throw()
{
    return (new std::string("command " + message + " runtime exception: " + this->exception))->c_str();
}
