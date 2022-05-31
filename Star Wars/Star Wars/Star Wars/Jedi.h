#ifndef JEDI
#define JEDI
#include "JediRank.h"
#include "NamedClass.h"
class Jedi : public NamedClass{
private:
	JediRank rank;
	short unsigned age;
	std::string lightsaberColor;
	double jediStrength;
public:
	Jedi(std::string = "<unnamed Jedi>", const char* ="YOUNGLING", short unsigned=18, std::string="blue", double=1);
	inline void demoteJedi(double multiplier = 0.1);
	inline void promoteJedi(double multiplier = 0.1);

	//getters:
	std::string getLightColor()const;
	const short unsigned getAge()const;
	const double getStrength()const;
	const JediRank getRank()const;
<<<<<<< Updated upstream

=======
	
	void loadFromFile(std::istream&) final;
	void saveToFile(std::ostream&)const final;
>>>>>>> Stashed changes
	void print(std::ostream&)const final;
};

#endif