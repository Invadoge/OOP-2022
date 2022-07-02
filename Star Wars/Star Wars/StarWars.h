#ifndef STAR_WARS
#define STAR_WARS
#include "Planet.h"

class StarWars {
	SortedVector<Planet> planets;
public:
	void clear() { planets.clear(); }
	auto getEnd() { return planets.getEnd(); }
	void addPlanet(std::string planetName);
	void addJedi(std::string, Jedi);
	void removeJedi(std::string, std::string);
	std::vector<Planet>::iterator findPlanet(std::string);
	std::vector<Planet>::const_iterator findPlanet(std::string)const;
	std::vector<Jedi>::iterator  findJedi(std::string,std::string* = nullptr);
	std::vector<Jedi>::const_iterator findJedi(std::string)const;
	void loadFromFile(std::istream&);
	void saveToFile(std::ostream&)const;
	Planet concatPlanetsByString(std::string, std::string)const;
};
#endif // !STAR_WARS
