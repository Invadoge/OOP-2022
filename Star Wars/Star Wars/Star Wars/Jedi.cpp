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
Jedi* Jedi::clone() const
{
	return new Jedi{ *this };
}

std::string Jedi::getString(size_t getType) const
{
	std::string answer;
	switch (getType) {
	case 1:
		return lightsaberColor;
	case 2:
		answer.append(rank.getRankName());
		return answer;
	default:
		return NamedClass::getName();
	}
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