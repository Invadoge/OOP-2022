#include "Planet.h"
#include <iostream>
Planet::Planet(std::string name):NamedClass{name}
{
}
void Planet::addMember(Jedi toAdd)
{
	inhabitants.addMember(toAdd);
}
void Planet::sort()
{
	inhabitants.sort();
}
void Planet::removeMember(std::string toRemove)
{
	inhabitants.removeMember(toRemove);
}
void Planet::loadFromFile(std::istream& in)
{
	inhabitants.clear();
	size_t toRead;
	Jedi tempJedi;
	NamedClass::loadFromFile(in);
	in >> toRead;
	in.ignore();
	for (size_t i = 0; i < toRead; i++) {
		tempJedi.loadFromFile(in);
		inhabitants.addMember(tempJedi);
	}
}
void Planet::saveToFile(std::ostream& out) const
{
	NamedClass::saveToFile(out);
	size_t length = inhabitants.size();
	out << length << '\n';
	for (size_t i = 0; i < length; i++) {
		inhabitants[i].saveToFile(out);
	}
}
void Planet::print(std::ostream& out)const
{
	out << "Planet ";
	NamedClass::print(out);
	inhabitants.print( out);
}

Planet concatPlanet(const Planet& lhs, const Planet& rhs)
{
	Planet result{ lhs };
	
	std::string combinedName = lhs.getName();
	combinedName.append(" and ");
	combinedName.append(rhs.getName());
	result.setName(combinedName);
	size_t rhsSize = rhs.size();
	for (size_t i = 0; i < rhsSize;i++) {
		result.addMember(rhs[i]);
	}
	return result;
}
