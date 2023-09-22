#ifndef COMMANDROUTERH
#define COMMANDROUTERH
#include <vector>

#include "Command.h"
#include "CommandNotFoundException.h"
#include "CommandRuntimeException.h"

class CommandRouter : public Command
{
public:
	// Hérité via Command
	virtual std::string execute(std::string args) override;
	virtual std::string getHelp();

	void add(Command* command);
	std::vector<Command*>* getRoutes();
private:
	std::vector<Command*> commands;
};

#endif // COMMANDROUTERH