#include "Planet.h"

Planet::Planet(std::string name):NamedClass{name}
{
}
Planet* Planet::clone()const {
	return new Planet{ *this };
}
void Planet::addMember(NamedClass* toAdd)
{
	SortedVector::addNamedClass(inhabitants, toAdd);
}
void Planet::sort()
{
	SortedVector::sort(inhabitants);
}
void Planet::removeMember(std::string toRemove)
{
	SortedVector::removeNamedClass(inhabitants, toRemove);
}
void Planet::print(std::ostream& out)
{
	NamedClass::print(out);
	SortedVector::print(inhabitants, out);
}
