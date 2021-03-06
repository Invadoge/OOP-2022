#ifndef JEDI_RANK
#define JEDI_RANK
#include <string>
#include <assert.h>
class JediRank {
private:
	size_t rankNumber=0;
	static constexpr char const* rankNames[] = { "YOUNGLING","INITIATE" , "PADAWAN",
		"KNIGHT-ASPIRANT","KNIGHT","MASTER","BATTLE_MASTER","GRAND_MASTER" };

	//short unsigned checkRankOfString(const std::string name);
	
	inline const size_t getRankCount()const;
public:
	JediRank(const size_t rank);
	JediRank(const char* rName);
	JediRank(std::string);
	const char* getRankName()const;
	void print(std::ostream&)const;
	JediRank& operator++();
	JediRank& operator--();
	friend bool operator==(const JediRank& first, const JediRank& second);
	friend bool operator!=(const JediRank& first, const JediRank& second);
	friend bool operator<(const JediRank& lhs, const JediRank& rhs);
	friend std::ostream& operator<<(std::ostream&, const JediRank&);
};

#endif