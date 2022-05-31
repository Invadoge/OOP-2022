#ifndef NAMED_CLASS
#define NAMED_CLASS
#include <string>
class NamedClass {
	std::string name;
public:
	NamedClass(std::string = "<unnamed>");
	std::string getName()const;
	virtual void print(std::ostream&)const;
	virtual void loadFromFile(std::istream&);
	virtual void saveToFile(std::ostream&)const;
	//Clone function to allow dynamic polymorphism
	virtual NamedClass* clone()const = 0;
	//Do not exist for this class, but are needed for Jedi
	virtual const short unsigned getAge()const=0;
	virtual const double getStrength()const=0;
	virtual std::string getString(size_t)const= 0 ;

	//Operators
	friend bool operator==(const NamedClass&, const NamedClass&);
	friend bool operator!=(const NamedClass&, const NamedClass&);
	friend bool operator<(const NamedClass&, const NamedClass&);
	friend std::ostream& operator<<(std::ostream&, const NamedClass&);
};
bool operator==(const NamedClass& lhs, const NamedClass& rhs) {
	return lhs.name == rhs.name;
}
bool operator!=(const NamedClass& lhs, const NamedClass& rhs) {
	return !(lhs.name == rhs.name);
}

bool operator<(const NamedClass& lhs, const NamedClass& rhs)
{
	return lhs.name < rhs.name;
}
std::ostream& operator<<(std::ostream& out, const NamedClass& nCl)
{
	out << nCl.name;
	return out;
}
#endif // !NAMED_CLASS

