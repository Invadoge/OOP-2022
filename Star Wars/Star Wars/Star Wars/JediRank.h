#ifndef _JEDI_RANK
#define _JEDI_RANK
#include <string>
#include <assert.h>
class JediRank {
private:
	size_t rankNumber=0;
	static constexpr char const* rankNames[] = { "YOUNGLING","INITIATE" , "PADAWAN",
		"KNIGHT-ASPIRANT","KNIGHT","MASTER","BATTLE_MASTER","GRAND_MASTER" };

	//short unsigned checkRankOfString(const std::string name);
	const char* getRankName()const { return rankNames[rankNumber]; }
	const size_t getRankCount()const {
		return  sizeof(rankNames) / sizeof(rankNames[0]);
	}
public:
	JediRank(const size_t rank) {
		size_t rankCount = getRankCount();
		assert(rank < rankCount && "Rank out of bounds!");
		rankNumber = rank;
	}
	JediRank(const char* rName) {
		size_t rankCount = getRankCount();
		bool validName{ false };
		for (size_t i = 0; i < rankCount; i++) {
			if (strcmp(rankNames[i], rName) == 0) {
				rankNumber = i;
				validName = true;
				break;
			}
		}
		assert(validName && "Invalid rank name!");
	}
	JediRank& operator++() {
		if (rankNumber < getRankCount() - 1)++rankNumber;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream&, JediRank);
};
std::ostream& operator<<(std::ostream& out, JediRank jR) {
	return out << jR.getRankName();
}
#endif