#include "StarWarsCommands.h"
void PromoteOrDemoteJedi::doExecute(const size_t commandToexecute)
{
	std::string jediName;
	input >> jediName;
	input.ignore();
	double multiplier;
	input >> multiplier;
	input.ignore();
	if (cmdNumber == 1)project->findJedi(jediName)->promoteJedi(multiplier);
	else project->findJedi(jediName)->demoteJedi(multiplier);
}