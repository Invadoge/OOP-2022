#ifndef STAR_WARS_PLANET
#define STAR_WARS_PLANET
#include "Jedi.h"
#include "SortedVector.h"
<<<<<<< Updated upstream
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
=======
class Planet : public NamedClass{
private:
	SortedVector<Jedi> inhabitants;

public:
	Planet(std::string="<unnamed planet>");
	bool (*strongerJedi)(const Jedi&, const Jedi&, const JediRank) =
		[](const Jedi& lhs, const Jedi& rhs, const JediRank) {return lhs.getStrength()<rhs.getStrength(); };
	
	using CompareJedi = bool (*)(const Jedi&,const Jedi&, const JediRank);
	Jedi getBestJediBy(CompareJedi criteria, const JediRank)const;
	std::string getMostFrequentLightSaber(const JediRank = "GRAND_MASTER");

	size_t size()const { return inhabitants.size(); };

	void addMember(Jedi);
	void sort();
	void removeMember(std::string);

	const Jedi& operator[](size_t position) const{ return inhabitants[position]; }
	friend Planet concatPlanet(const Planet&, const Planet&);
	void loadFromFile(std::istream&)final;
	void saveToFile(std::ostream&)const final;
	void print(std::ostream&)const;
};
#endif // !_STAR_WARS_PLANET

inline Jedi Planet::getBestJediBy(CompareJedi criteria, const JediRank inCriteria) const
>>>>>>> Stashed changes
{
	size_t length = inhabitants.size();
	assert(length > 0 && "No jedi on this planet!");
	if (length == 1)return inhabitants[0];
<<<<<<< Updated upstream
	Jedi answer = (criteria(inhabitants[0], inhabitants[1]))? inhabitants[1] : inhabitants[0];
=======
	Jedi answer = (criteria(inhabitants[0], inhabitants[1], inCriteria))? inhabitants[1] : inhabitants[0];
>>>>>>> Stashed changes
	for (size_t i = 1; i < length - 1;i++) {
		if(criteria(answer, inhabitants[i], inCriteria))answer=inhabitants[i];
	}
	return answer;
}

inline std::string Planet::getMostFrequentLightSaber(const JediRank neededRank)
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
		if (inhabitants[i].getLightColor() != currentLS) {
			currentLS = inhabitants[i].getLightColor();
			currCount = 0;
		}
		else {
			currCount++;
			if (currCount > maxCount) {
				mostFrequentLS = currentLS;
				maxCount = currCount;
			}
		}
	}
	inhabitants.sort();
	if (mostFrequentLS == std::string())mostFrequentLS = "No lightsaber found with current criteria!";
	return mostFrequentLS;
}
