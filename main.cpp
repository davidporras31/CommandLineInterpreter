

#include <iostream>
#include "Console.h"
int main()
{
    std::cout << "Hello World!\n";
    Console console;
    Console::addBasicCommand(&console);
    std::cout << console.commandeExecute("list");
    std::cout << console.autoCompleteCommand("l");
}

