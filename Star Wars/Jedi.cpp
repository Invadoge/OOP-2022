#include "Jedi.h"
#include <iostream>
void Jedi::promoteJedi(double multiplier) {
	assert(multiplier > 0 && "Multiplier must be above 0!\n");
	++rank;
	jediStrength *= (1 + multiplier);
}
void Jedi::demoteJedi(double multiplier) {
	assert(multiplier > 0 && "Multiplier must be above 0!\n");
	--rank;
	jediStrength *= (1 - multiplier);
}
std::string Jedi::getLightColor() const
{
	return lightsaberColor;
}
const short unsigned Jedi::getAge() const
{
	return age;
}
const double Jedi::getStrength() const
{
	return jediStrength;
}
const JediRank Jedi::getRank() const
{
	return rank;
}

void Jedi::loadFromFile(std::istream& in)
{
	NamedClass::loadFromFile(in);
	in >> age;
	size_t temp;
	in >> temp;
	rank =  temp;
	in >> jediStrength;
	in.ignore();
	std::getline(in, lightsaberColor);
}

void Jedi::saveToFile(std::ostream& out) const
{
	NamedClass::saveToFile(out);
	out << age <<'\n';
	out<< rank << '\n';
	out << jediStrength << '\n';
	out << lightsaberColor << '\n';
}

void Jedi::print(std::ostream& out) const
{
	out << "Jedi ";
	NamedClass::print(out);
	out << "Age: " << age;
	out << "\nRank: ";
	rank.print(out);
	out << "\nStrength: " << jediStrength;
	out << "\nLightsaber color: " << lightsaberColor << '\n';
}
Jedi::Jedi(std::string nName, const char* nRank, short unsigned nAge, std::string nColor, double nStrength):
	NamedClass{ nName }, rank{ nRank }, age{ nAge }, lightsaberColor{ nColor }, jediStrength{ nStrength }
{}
Jedi::Jedi(std::string nName, std::string nRank, short unsigned nAge, std::string nColor, double nStrength):
	NamedClass{ nName }, rank{ nRank }, age{ nAge }, lightsaberColor{ nColor }, jediStrength{ nStrength }
{}