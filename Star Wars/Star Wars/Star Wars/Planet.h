#ifndef STAR_WARS_PLANET
#define STAR_WARS_PLANET
#include "Jedi.h"
#include "SortedVector.h"
class Planet : public NamedClass, public SortedVector{
private:
	std::vector<NamedClass*> inhabitants;

public:
	Planet(std::string="<unnamed planet>");
	bool (*strongerJedi)(const NamedClass*, const NamedClass*) =
		[](const NamedClass* lhs, const NamedClass* rhs) {return true; };
	
	using CompareJedi = bool (*)(const NamedClass*,const NamedClass*);
	NamedClass* getBestJediBy(CompareJedi criteria)const;
	//std::string getMostFrequentLightSaber(JediRank = "GRAND_MASTER") const;
	//Planet concatenateSort(const Planet& other)const;
	Planet* clone()const final;
	//unneeded getters, but should be declared, otherwise the class will be abstract
	const short unsigned getAge()const { return 0; }
	const double getStrength()const { return 0; }
	std::string getString(size_t)const { return NamedClass::getName(); }

	inline void addMember(NamedClass*);
	inline void sort();
	inline void removeMember(std::string);
	inline void print(std::ostream&);
};
#endif // !_STAR_WARS_PLANET

inline NamedClass* Planet::getBestJediBy(CompareJedi criteria) const
{
	size_t length = inhabitants.size();
	assert(length > 0 && "No jedi on this planet!");
	if (length == 1)return inhabitants[0];
	NamedClass* answer = (criteria(inhabitants[0], inhabitants[1]))? inhabitants[1] : inhabitants[0];
	for (size_t i = 1; i < length - 1;i++) {
		if(criteria(answer, inhabitants[i]))answer=inhabitants[i];
	}
	return answer;
}
