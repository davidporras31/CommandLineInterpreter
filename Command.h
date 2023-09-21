#ifndef COMMANDH
#define COMMANDH
#include <string>

class Command
{
public:
	/*
	* \brief the executed methode when calling command from the console
	*
	* \param args the command argument
	*/
	virtual std::string execute(std::string args) = 0;

	/*
	* \brief get the name command
	* 
	* \return the command name
	*/
	std::string getName();
	void setName(std::string name);

	/*
	* \brief get the message use in help command
	* 
	* \return the help message
	*/
	std::string getHelp();
	void setHelp(std::string name);
private:
	std::string name, help;
};

#endif // COMMANDH