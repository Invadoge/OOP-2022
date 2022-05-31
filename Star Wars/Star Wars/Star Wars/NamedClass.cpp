#include "NamedClass.h"
#include <iostream>
NamedClass::NamedClass(std::string nName):name{nName}
{
}

std::string NamedClass::getName() const
{
	return name;
}
void NamedClass::print(std::ostream& out) const
{
	out << "Name: "<< name << '\n';
}
void NamedClass::loadFromFile(std::istream& in)
{
	std::getline(in,name);
}
void NamedClass::saveToFile(std::ostream& out) const
{
	out << name <<'\n';
}