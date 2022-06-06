#ifndef STAR_WARS_COMMANDS
#define STAR_WARS_COMMANDS
#include "Commands.h"
#include "StarWars.h"
#include <iostream>
#include <fstream>
class Close : public Command {
	std::string* fileName;
	StarWars* project;
	void doExecute(const size_t commandToexecute) final{
		fileName->clear();
		project->clear();
	}
public:
	Close(std::string* filePtr, StarWars* ptr) :fileName{ filePtr }, project{ ptr } {}
};

class Open : public Command {
	std::istream& input;
	StarWars* project;
	std::string* stringTochange;
	bool validFileName(const std::string fileName) const {
		size_t pos = fileName.find(".");
		if (pos == std::string::npos)return false;

		std::string ext = fileName.substr(pos);
		if (ext != ".txt")return false;
		return true;
	}
	void doExecute(const size_t commandToexecute)final {
		std::string fileName;
		std::getline(input, fileName);
		assert(validFileName(fileName) && "Invalid file name! Try a file with ending in .txt\n");
		*stringTochange = fileName;
		std::ifstream file;
		file.open(fileName);
		if (file.is_open()){//doing it like this instead of an assert so the program doesn't throw user out if there is no file
			if (file.peek() != std::ifstream::traits_type::eof())project->loadFromFile(file);
			file.close();
		}
	}
public:
	Open(std::istream& in, std::string* strptr, StarWars* ptr) :input{ in }, project{ ptr }, stringTochange{ strptr }{}
};

class Save : public Command {
	std::string fileName;
	StarWars* project;

	bool validFileName(const std::string fileName) const {
		size_t pos = fileName.find(".");
		if (pos == std::string::npos)return false;

		std::string ext = fileName.substr(pos);
		if (ext != ".txt")return false;
		return true;
	}
	void doExecute(const size_t commandToexecute)final {
		assert(validFileName(fileName) && "Invalid file name! Try a file with ending in .txt\n");
		std::ofstream file(fileName);
		assert(file.is_open() && "Could not open file!\n");
		project->saveToFile(file);
		file.close();
	}
public:
	Save(std::string name, StarWars* ptr) :fileName{ name }, project{ ptr }{}
};

class AddPlanet : public Command {
	std::istream& input;
	StarWars* project;
	void doExecute(const size_t commandToexecute)final {
		std::string planetName;
		input >> planetName;
		input.ignore();
		project->addPlanet(planetName);
	}
public:
	AddPlanet(std::istream& in, StarWars* ptr):input{in}, project{ptr}{}
};
class RemoveJedi : public Command {
	std::istream& input;
	StarWars* project;
	void doExecute(const size_t commandToexecute)final {
		std::string jediName;
		std::string planetName;
		input >> planetName;
		input.ignore();
		input >> jediName;
		input.ignore();
		project->removeJedi(planetName, jediName);
	}
public:
	RemoveJedi(std::istream& in, StarWars* ptr) :input{ in }, project{ ptr }{}
};
class PromoteOrDemoteJedi : public Command {
	std::istream& input;
	StarWars* project;
	size_t cmdNumber;
	void doExecute(const size_t commandToexecute)final;
public:
	PromoteOrDemoteJedi(std::istream& in, StarWars* ptr, size_t cmd=1) :input{ in }, project{ ptr }, cmdNumber{ cmd }{}
};
class GetStrongestJedi : public Command {
	std::ostream& output;
	std::istream& input;
	StarWars* project;
	bool (*strongerJedi)(const Jedi&, const Jedi&, const JediRank) =
		[](const Jedi& lhs, const Jedi& rhs, const JediRank) {return lhs.getStrength() >= rhs.getStrength(); };
	void doExecute(const size_t commandToexecute)final {
		std::string planetName;
		input >> planetName;
		input.ignore();
		project->findPlanet(planetName)->getBestJediBy(strongerJedi, "Doesn't matter").print(output);
	}
public:
	GetStrongestJedi(std::ostream& out, std::istream& in, StarWars* ptr) :output{ out },input { in }, project{ ptr }{}
};
class GetYoungestJedi : public Command {
	std::ostream& output;
	std::istream& input;
	StarWars* project;
	bool (*youngerJedi)(const Jedi&, const Jedi&, const JediRank) =
		[](const Jedi& lhs, const Jedi& rhs, const JediRank needed) {
		if (lhs.getRank() == needed && rhs.getRank() == needed)return rhs.getAge() >= lhs.getAge();
		/*if (lhs.getRank() != needed && rhs.getRank() == needed)return false;
		if (lhs.getRank() != needed && rhs.getRank() != needed)return false;
		if (lhs.getRank() == needed && rhs.getRank() != needed)return true;*/
		return lhs.getRank() == needed;
	};
	void doExecute(const size_t commandToexecute)final {
		std::string planetName;
		std::string jediRank;
		input >> planetName;
		input.ignore();
		input >> jediRank;
		input.ignore();
		project->findPlanet(planetName)->getBestJediBy(youngerJedi, { jediRank }).print(output);
	}
public:
	GetYoungestJedi(std::ostream& out, std::istream& in, StarWars* ptr) :output{ out }, input { in }, project{ ptr }{}
};
class GetMostUsedSaber : public Command{
	std::ostream& output;
	std::istream& input;
	StarWars* project;
	void doExecute(const size_t commandToexecute)final {
		std::string planetName;
		std::string jediRank;
		std::getline(input, planetName);
		size_t pos = planetName.find(" ");
		if (pos != std::string::npos) {
			assert(planetName.length() >= pos + 1 && "Invalid GetMostUsedSaber command!\n");
			jediRank = planetName.substr(pos + 1);
			planetName = planetName.substr(0, pos);
		}
		else jediRank = "GRAND_MASTER";
		output << "Most used lightsaber by jedi of rank " << jediRank << " is :"
			<< project->findPlanet(planetName)->getMostFrequentLightSaber(jediRank) << '\n';
	}
public:
	GetMostUsedSaber(std::ostream& out, std::istream& in, StarWars* ptr) :output{ out }, input{ in }, project{ ptr }{}
};
class PrintJediOrPlanet : public Command {
	std::ostream& output;
	std::istream& input;
	StarWars* project;
	void doExecute(const size_t commandToexecute)final {
		std::string name;
		std::getline(input, name);
		auto toPrint = project->findPlanet(name);
		if (toPrint == project->getEnd()) {
			auto jToPrint = project->findJedi(name);//findJedi has built in error handling
			jToPrint->print(output);
		}
		else toPrint->print(output);
	}
public:
	PrintJediOrPlanet(std::ostream& out, std::istream& in, StarWars* ptr) :output{ out }, input{ in }, project{ ptr }{}
};
class CombinePlanets : public Command {
	std::string lhs;
	std::string rhs;
	std::istream& input;
	std::ostream& output;
	StarWars* project;
	void doExecute(const size_t commandToexecute)final {
		project->concatPlanetsByString(lhs, rhs).print(output);
	}
public:
	CombinePlanets(std::string newlhs, std::string newrhs, std::istream& in, std::ostream& out, StarWars* ptr) :lhs{ newlhs }, rhs{newrhs}
		, input{ in }, output{ out }, project{ ptr }{}
};
class CreateJedi : public Command {
	std::istream& input;
	StarWars* project;
	void doExecute(const size_t commandToexecute)final {
		std::string planetName;
		std::string jediName;
		std::string jediRank;
		short unsigned jediAge;
		std::string saberColor;
		double jediStrength;
		input >> planetName;
		input.ignore();
		input >> jediName;
		input.ignore();
		input >> jediRank;
		input.ignore();
		input >> jediAge;
		input.ignore();
		input >> saberColor;
		input.ignore();
		input >> jediStrength;
		input.ignore();
		project->addJedi(planetName, { jediName, jediRank, jediAge, saberColor, jediStrength });
	}
public:
	CreateJedi(std::istream& in, StarWars* ptr) :input{ in }, project{ ptr }{}
};
#endif // !STAR_WARS_COMMANDS

