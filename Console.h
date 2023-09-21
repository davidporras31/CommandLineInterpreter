#ifndef CONSOLEH
#define CONSOLEH
#include <string>
#include <vector>
#include <exception>

#include "Command.h"
#include "CommandNotFoundException.h"
#include "CommandRuntimeException.h"

#include "HelpCommand.h"
#include "ListCommand.h"


class Console
{
public:
    Console();


    /*
    * \brief add basic command to the console
    *
    * \param console where to add command
    */
    static void addBasicCommand(Console * console);

    /*
    * \brief add command to the console
    *
    * \param command to add in console
    */
    void addCommand(Command* command);
    /*
    * \brief remove command to the console
    *
    * \param id the id of the command to remove from console
    */
    void removeCommand(size_t id);/*
    * \brief remove command to the console
    *
    * \param name the name of the command to remove from console
    */
    void removeCommand(std::string name);

    /*
    * \brief execute command from console
    *
    * \param buffer the command to execute command
    *
    * \return the return from command
    */
    std::string commandeExecute(std::string buffer);

    /*
    * \brief auto complete command
    *
    * \param buffer the command to auto complete command
    * 
    * \return the auto completed command
    */
    std::string autoCompleteCommand(std::string buffer);
private:
    std::vector<Command*> commands;
    std::vector<Command*>* getCommands();
};

#endif // CONSOLEH