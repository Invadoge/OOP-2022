#ifndef STAR_WARS_PLANET
#define STAR_WARS_PLANET
#include "Jedi.h"
#include "SortedVector.h"
#include <iostream>
class Planet : public NamedClass{
private:
	SortedVector<Jedi> inhabitants;

public:
	Planet(std::string="<unnamed planet>");
	using CompareJedi = bool (*)(const Jedi&,const Jedi&, const JediRank);
	Jedi getBestJediBy(CompareJedi criteria, const JediRank)const;
	std::string getMostFrequentLightSaber(const JediRank = "GRAND_MASTER");

	size_t size()const { return inhabitants.size(); };

	void addMember(Jedi);
	void sort();
	void removeMember(std::string);
	auto getEnd()const {
		return inhabitants.getEnd();
	}
	std::string getName()const {
		return NamedClass::getName();
	}
	auto findByName(std::string name) { 
		auto result = inhabitants.findByName(name);
		return result;
	}
	auto findByName(std::string name) const{
		auto result = inhabitants.findByName(name);
		return result;
	}
	const Jedi& operator[](size_t position) const{ return inhabitants[position]; }
	friend Planet concatPlanet(const Planet&, const Planet&);
	void loadFromFile(std::istream&)final;
	void saveToFile(std::ostream&)const final;
	void print(std::ostream&)const final;
	void printStyles(std::ostream&, const size_t=0);//for different ways of printing
};
#endif // !_STAR_WARS_PLANET


