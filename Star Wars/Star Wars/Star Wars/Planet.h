#ifndef STAR_WARS_PLANET
#define STAR_WARS_PLANET
#include "Jedi.h"
#include "SortedVector.h"
class Planet : public NamedClass, public SortedVector<Jedi>{
private:
	std::vector<Jedi> inhabitants;

public:
	Planet(std::string="<unnamed planet>");
	bool (*strongerJedi)(const Jedi, const Jedi) =
		[](const Jedi lhs, const Jedi rhs) {return lhs.getStrength() < rhs.getStrength(); };
	
	using CompareJedi = bool (*)(const Jedi&,const Jedi&);
	Jedi getBestJediBy(CompareJedi criteria)const;
	//std::string getMostFrequentLightSaber(JediRank = "GRAND_MASTER") const;
	//Planet concatenateSort(const Planet& other)const;
	inline void addMember(Jedi);
	inline void sort();
	inline void removeMember(std::string);
	inline void print(std::ostream&);
};
#endif // !_STAR_WARS_PLANET

inline Jedi Planet::getBestJediBy(CompareJedi criteria) const
{
	size_t length = inhabitants.size();
	assert(length > 0 && "No jedi on this planet!");
	if (length == 1)return inhabitants[0];
	Jedi answer = (criteria(inhabitants[0], inhabitants[1]))? inhabitants[1] : inhabitants[0];
	for (size_t i = 1; i < length - 1;i++) {
		if(criteria(answer, inhabitants[i]))answer=inhabitants[i];
	}
	return answer;
}
