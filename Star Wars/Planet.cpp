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

void Planet::printStyles(std::ostream& out, const size_t style)
{
	bool (*sortByRankAlphabetical)(const Jedi & lhs, const Jedi & rhs) =
		[](const Jedi& lhs, const Jedi& rhs)
	{return lhs.getRank() < rhs.getRank() || lhs.getRank() == rhs.getRank() && lhs.getName() < rhs.getName(); };
	switch (style){
	case 0: // print in rank order and alphabetical
		
		inhabitants.sort(sortByRankAlphabetical);
		break;
	default:
		break;
		//currently empty, can be filled in the future
	}
	print(out);
	inhabitants.sort();
}
Jedi Planet::getBestJediBy(CompareJedi criteria, const JediRank inCriteria) const
{
	//NOTE: think of criteria as operator >=
	size_t length = inhabitants.size();
	assert(length > 0 && "No jedi on this planet!");
	Jedi answer;
	if (length == 1)answer = inhabitants[0];
	else {
		answer = (criteria(inhabitants[0], inhabitants[1], inCriteria)) ? inhabitants[0] : inhabitants[1];
		for (size_t i = 1; i < length; i++) {
			if (criteria(inhabitants[i], answer, inCriteria))answer = inhabitants[i];
		}
	}
	assert(criteria(answer, answer, inCriteria) && "No jedi on planet found that meets criteria!");//if criteria needs a specific Jedirank
	return answer;
}

std::string Planet::getMostFrequentLightSaber(const JediRank neededRank)
{
	size_t maxCount = 0;
	size_t currCount = 0;
	size_t length = inhabitants.size();
	std::string currentLS;
	std::string mostFrequentLS;
	bool (*lightsaberName)(const Jedi&, const Jedi&) =
		[](const Jedi& lhs, const Jedi& rhs) {return lhs.getLightColor() < rhs.getLightColor(); };
	inhabitants.sort(lightsaberName);
	for (size_t i = 0; i < length; i++) {
		if (inhabitants[i].getRank() != neededRank)continue;
		if (inhabitants[i].getLightColor() != currentLS) {
			currentLS = inhabitants[i].getLightColor();
			currCount = 1;
		}
		else {
			currCount++;
		}
		if (currCount > maxCount) {
			mostFrequentLS = currentLS;
			maxCount = currCount;
		}
	}
	inhabitants.sort();
	if (mostFrequentLS == std::string())mostFrequentLS = "No lightsaber found with current criteria!";
	return mostFrequentLS;
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
