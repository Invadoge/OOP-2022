#ifndef SORTED_VECTOR
#define SORTED_VECTOR
#include "NamedClass.h"
#include <vector>
#include <string>
class SortedVector {
private:

	//bool(*compareNamedClass)(NamedClass*, NamedClass*) = [](NamedClass* lhs, NamedClass* rhs) { return lhs < rhs; };

	auto findByName(std::vector<NamedClass*>&, std::string);
	void insertSorted(std::vector<NamedClass*>&, NamedClass*);
public:
	void addNamedClass(std::vector<NamedClass*>&, NamedClass*);
	void sort(std::vector<NamedClass*>&);
	void removeNamedClass(std::vector<NamedClass*>&, std::string);
	void print(std::vector<NamedClass*>&, std::ostream&);
};


#endif // !SORTED_VECTOR

