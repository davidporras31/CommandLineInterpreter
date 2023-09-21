#ifndef COMMANDNOTFOUNDEXCEPTION_H
#define COMMANDNOTFOUNDEXCEPTION_H

#include <exception>
#include <string>


class CommandNotFoundException :
    public std::exception
{
public:
    CommandNotFoundException(std::string message);
    const char* what() const throw ();
private:
    std::string message;
};

#endif