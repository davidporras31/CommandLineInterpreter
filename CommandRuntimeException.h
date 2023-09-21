#ifndef COMMANDRUNTIMEEXCEPTION_H
#define COMMANDRUNTIMEEXCEPTION_H

#include <exception>
#include <string>


class CommandRuntimeException :
    public std::exception
{
public:
    CommandRuntimeException(std::string message , std::string exception);
    const char* what() const throw ();
private:
    std::string message;
    std::string exception;
};

#endif