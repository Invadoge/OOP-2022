#include "Parser.h"
Command* CMDParser::doParse() {
	std::string command;
	input >> command;
	input.ignore();
	if (command == "help") {//the only command in both phases
		return new Help{ output };
	}
	else if (phase == 0) {//No open file
		if (command == "open") {
			phase = 1;
			return new Open{ input, &fileName, &project };
		}
		if (command == "exit") {
			phase = -1;//so that parser.done() returns true
			return new Exit{ output };
		}
	}
	else if (phase == 1) {//A file has been opened
		if (command == "save") {
			return new Save{ fileName , &project };
		}
		if (command == "saveas") {
			std::string toSave;
			std::getline(input, toSave);
			return new Save{ toSave, &project };
		}
		if (command == "close") {
			phase = 0;
			return new Close{ &fileName,&project };
		}
		if (command == "add_planet") {
			return new AddPlanet{ input, &project };
		}
		if (command == "create_jedi") {
			return new CreateJedi{ input, &project };
		}
		if (command == "remove_jedi") {
			return new RemoveJedi{ input, &project };
		}
		if (command == "promote_jedi") {
			return new PromoteOrDemoteJedi{ input, &project, 1 };
		}
		if (command == "demote_jedi") {
			return new PromoteOrDemoteJedi{ input, &project, 0 };
		}
		if (command == "get_strongest_jedi") {
			return new GetStrongestJedi{ output, input, &project };
		}
		if (command == "get_youngest_jedi") {
			return new GetYoungestJedi{ output, input, &project };
		}
		if (command == "get_most_used_saber_color") {
			return new GetMostUsedSaber{ output, input, &project };
		}
		if (command == "print") {
			return new PrintJediOrPlanet{ output, input, &project };
		}
		if (project.findPlanet(command) != project.getEnd()) {
			std::string rest;
			std::getline(input, rest);
			size_t pos = rest.find("+ ");
			assert(rest.length() >= pos + 3);
			rest = rest.substr(pos + 2);
			return new CombinePlanets{ command, rest, input, output, &project };
		}
	}
	return new Invalid{ output };
}