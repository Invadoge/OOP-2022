#include "Planet.h"

Planet::Planet(std::string name):NamedClass{name}
{
}
void Planet::addMember(Jedi toAdd)
{
	SortedVector<Jedi>::addMember(inhabitants, toAdd);
}
void Planet::sort()
{
	SortedVector<Jedi>::sort(inhabitants);
}
void Planet::removeMember(std::string toRemove)
{
	SortedVector<Jedi>::removeMember(inhabitants, toRemove);
}
void Planet::print(std::ostream& out)
{
	NamedClass::print(out);
	SortedVector<Jedi>::print(inhabitants, out);
}
