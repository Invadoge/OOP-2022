#include "Jedi.h"
#include <iostream>
void Jedi::promoteJedi(double multiplier) {
	assert(multiplier > 0 && "Multiplier must be above 0!\n");
	++rank;
	jediStrength *= (1 + multiplier);
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
void Jedi::print(std::ostream& out) const
{
	NamedClass::print(out);
	out << "Age: " << age;
	out << "\nRank: " << rank;
	out << "\nStrength: " << jediStrength;
	out << "\nLightsaber color: " << lightsaberColor << '\n';
}
Jedi::Jedi(std::string nName, const char* nRank, short unsigned nAge, std::string nColor, double strength):
	NamedClass{ nName }, rank{ nRank }, age{ nAge }, lightsaberColor{ nColor }, jediStrength{ strength }
{}
void Jedi::demoteJedi(double multiplier) {
	assert(multiplier > 0 && "Multiplier must be above 0!\n");
	--rank;
	jediStrength *= (1 - multiplier);
}