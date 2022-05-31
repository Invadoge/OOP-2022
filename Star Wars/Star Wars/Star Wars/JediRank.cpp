#include "JediRank.h"
#include <iostream>
inline const char* JediRank::getRankName()const {
	return rankNames[rankNumber]; 
}

void JediRank::print(std::ostream& out) const
{
	out << getRankName();
}

inline const size_t JediRank::getRankCount()const {
	return  sizeof(rankNames) / sizeof(rankNames[0]);
}
JediRank::JediRank(const size_t rank) {
	size_t rankCount = getRankCount();
	assert(rank < rankCount && "Rank out of bounds!");
	rankNumber = rank;
}
JediRank::JediRank(const char* rName) {
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
JediRank& JediRank::operator++() {
	if (rankNumber < getRankCount() - 1)++rankNumber;
	return *this;
}
JediRank& JediRank::operator--() {
	if (rankNumber > 0)--rankNumber;
	return *this;
}
bool operator==(const JediRank& first, const JediRank& second) {
	return first.rankNumber == second.rankNumber;
}
bool operator<(const JediRank& lhs, const JediRank& rhs) {
	return lhs.rankNumber < rhs.rankNumber;
}
std::ostream& operator<<(std::ostream& out, const JediRank& jR) {
	out << jR.rankNumber;
	return out;
}