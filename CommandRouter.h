#ifndef COMMANDROUTERH
#define COMMANDROUTERH
#include <vector>

#include "Command.h"
#include "CommandNotFoundException.h"

class CommandLineInterpreter : public Command
{
public:
	// Hérité via Command
	virtual std::string execute(std::string args) override;

	void add(Command* command);
	std::vector<Command*>* getRoutes();
private:
	std::vector<Command*> commands;
};

#endif // COMMANDROUTERH