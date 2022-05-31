#include "SortedVector.h"

#include <assert.h>
#include <algorithm>

auto SortedVector::findByName(std::vector<NamedClass*>& members, std::string name)
{
	for (auto i = members.begin(); i != members.end(); i++) {
		if ((*i)->getName() == name)return i;
	}
	return members.end();
}
void SortedVector::insertSorted(std::vector<NamedClass*>& members, NamedClass* newMemb)
{
	auto insertionPoint = std::upper_bound(members.begin(), members.end(), newMemb);
	members.insert(insertionPoint, newMemb);
}
void SortedVector::addNamedClass(std::vector<NamedClass*>& members, NamedClass* newMemb)
{
	assert(findByName(members, newMemb->getName()) == members.end());
	insertSorted(members, newMemb);
}
void SortedVector::sort(std::vector<NamedClass*>& members)
{
	std::sort(members.begin(), members.end());
}
void SortedVector::removeNamedClass(std::vector<NamedClass*>& members, std::string toRemove)
{
	auto found = findByName(members, toRemove);
	assert(found != members.end() && "No such member exists here!");
	members.erase(found);
}
void SortedVector::print(std::vector<NamedClass*>& members, std::ostream& out)
{
	for (auto i : members) {
		i->print(out);
	}
}