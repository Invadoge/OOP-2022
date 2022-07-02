#include "StarWars.h"
#include <iostream>
void StarWars::addPlanet(std::string planetName)
{
	assert(findPlanet(planetName) == planets.getEnd() && "Planet already in system!\n");
	Planet toAdd{ planetName };
	planets.addMember(toAdd);
}
void StarWars::addJedi(std::string planetName, Jedi jedi){
	auto found = findPlanet(planetName);
	assert(found != planets.getEnd() && "No such planet in project!");
	found->addMember(jedi);
}
void StarWars::removeJedi(std::string planetName, std::string jediName)
{
	findPlanet(planetName)->removeMember(jediName);
}
std::vector<Planet>::iterator StarWars::findPlanet(std::string name) 
{
	auto found = planets.findByName(name);
	return found;
}
std::vector<Planet>::const_iterator StarWars::findPlanet(std::string name)const
{
	auto found = planets.findByName(name);
	return found;
}

std::vector<Jedi>::iterator StarWars::findJedi(std::string name,std::string* pname){
	size_t length = planets.size();
	assert(length > 0 && "No planets in project!\n");
	std::vector<Jedi>::iterator foundJedi;
	for (size_t i = 0; i < length; i++) {
		foundJedi = planets[i].findByName(name);
		if (foundJedi != planets[i].getEnd()) {
			if (pname != nullptr) {
				*pname = planets[i].getName();
			}
			return foundJedi;
		}
	}
	assert(false && "No jedi with such name found!\n");//need this error handling because it can't be checked
	return foundJedi;
}

std::vector<Jedi>::const_iterator StarWars::findJedi(std::string name) const
{
	size_t length = planets.size();
	assert(length > 0 && "No planets in project!\n");
	auto foundJedi = planets[0].findByName(name);
	if (foundJedi != planets[0].getEnd())return foundJedi;
	for (size_t i = 1; i < length; i++) {
		foundJedi = planets[i].findByName(name);
		if (foundJedi != planets[i].getEnd())return foundJedi;
	}
	assert(false && "No jedi with such name found!\n");//need this error handling because it can't be checked
	return foundJedi;
}

void StarWars::loadFromFile(std::istream& in)
{
	clear();
	size_t toRead;
	in >> toRead;
	in.ignore();
	Planet toInclude;
	for (size_t i = 0; i < toRead; i++) {
		toInclude.loadFromFile(in);
		planets.addMember(toInclude);
	}
}

void StarWars::saveToFile(std::ostream& out) const
{
	size_t length = planets.size();
	out << length << '\n';
	for (size_t i = 0; i < length; i++) {
		planets[i].saveToFile(out);
	}
}

Planet StarWars::concatPlanetsByString(std::string lhs, std::string rhs) const
{
	auto lhsPlanet = findPlanet(lhs);
	auto rhsPlanet = findPlanet(rhs);
	assert(lhsPlanet != planets.getEnd() && rhsPlanet != planets.getEnd() && "At least one of the planets not in database!\n");
	return concatPlanet(*lhsPlanet, *rhsPlanet);
}
