#ifndef NAMED_CLASS
#define NAMED_CLASS
#include <string>
class NamedClass {
	std::string name;
public:
	NamedClass(std::string = "<unnamed>");
	inline void setName(std::string other) { name = other; }
	std::string getName()const;
	virtual void print(std::ostream&)const;
	virtual void loadFromFile(std::istream&);
	virtual void saveToFile(std::ostream&)const;

	//Operators
	friend bool operator==(const NamedClass&, const NamedClass&);
	friend bool operator!=(const NamedClass&, const NamedClass&);
	friend bool operator<(const NamedClass&, const NamedClass&);
	friend std::ostream& operator<<(std::ostream&, const NamedClass&);
};

#endif // !NAMED_CLASS

