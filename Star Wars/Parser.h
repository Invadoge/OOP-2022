#ifndef STAR_WARS_PARSER
#define STAR_WARS_PARSER
#include "StarWarsCommands.h"
class CMDParser {
	StarWars project;
	std::istream& input;
	std::ostream& output;
	std::string fileName;
	int phase;//for checking if program should exit, and execute programs with different parameters
	Command* doParse();
public:
	Command* parse(){
		Command* c = doParse();
		if (input.fail())
		{
			input.clear();
			input.ignore();
			delete c;
			return new Invalid{ output };
		}

		return c;
	}
	CMDParser(StarWars& pr, std::istream& in, std::ostream& out) : project{ pr }, input{ in }, output{ out }, phase{ 0 }{}
	bool done() const{
		return static_cast<bool>(!input) || phase == -1;
	}
	int getPhase()const { return phase; }
};
class UserInterface {
	CMDParser parser;
	std::istream& input;
	std::ostream& output;
	void evaluate(Command* command){
		command->execute(parser.getPhase());//currently getPhase() is used for the help command
											//but more phase dependant commands can be added
	}

	Command* read(){
		return parser.parse();
	}
	bool done()const {
		return parser.done();
	}
public:
	void UI() {
		Command* command;
		while (!done()) {
			command = read();
			evaluate(command);
			delete[]command;
		}
	}
	UserInterface(StarWars& pr, std::istream& in, std::ostream& out) : input{ in }, output{ out }
		, parser{ pr, in, out }{}
};
#endif // !STAR_WARS_PARSER

