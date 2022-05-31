#ifndef SORTED_VECTOR
#define SORTED_VECTOR
#include <vector>
#include <string>
<<<<<<< Updated upstream
#include <algorithm>
template <class Member>
class SortedVector {
private:

	//bool(*compareMembers)(Member, Member) = [](Member lhs, Member rhs) { return lhs < rhs; };

	auto findByName(std::vector<Member>&, std::string);
	void insertSorted(std::vector<Member>&, Member);
public:
	void addMember(std::vector<Member>&, Member);
	void sort(std::vector<Member>&);
	void removeMember(std::vector<Member>&, std::string);
	void print(std::vector<Member>&, std::ostream&);
};
template <class Member>
auto SortedVector<Member>::findByName(std::vector<Member>& members, std::string name)
=======
#include <assert.h>
#include <algorithm>


template <class Member>
class SortedVector {
private:
	std::vector<Member> members;
	static bool isLess(const Member& lhs, const Member& rhs) { return lhs < rhs; };
	void insertSorted(Member);
public:

	auto findByName(std::string);
	auto getEnd()const { return members.end(); }//for findByName comparison
	void addMember(Member);
	using Comparator = bool(*)(const Member&, const Member&);
	void sort(Comparator=SortedVector::isLess);
	void removeMember(std::string);
	void print(std::ostream&)const;
	size_t size()const;
	void clear();
	const Member& operator[](size_t position)const;
	Member& operator[](size_t position);
};
template <class Member>
inline auto SortedVector<Member>::findByName(std::string name)
>>>>>>> Stashed changes
{
	for (auto i = members.begin(); i != members.end(); i++) {
		if (i->getName() == name)return i;
	}
	return members.end();
}
template <class Member>
<<<<<<< Updated upstream
void SortedVector<Member>::insertSorted(std::vector<Member>& members, Member newMemb)
=======
inline void SortedVector<Member>::insertSorted(Member newMemb)
>>>>>>> Stashed changes
{
	auto insertionPoint = std::upper_bound(members.begin(), members.end(), newMemb);
	members.insert(insertionPoint, newMemb);
}
template <class Member>
<<<<<<< Updated upstream
void SortedVector<Member>::addMember(std::vector<Member>& members, Member newMemb)
{
	assert(findByName(members, newMemb.getName()) == members.end());
	insertSorted(members, newMemb);
}
template <class Member>
void SortedVector<Member>::sort(std::vector<Member>& members)
{
	std::sort(members.begin(), members.end());
}
template <class Member>
void SortedVector<Member>::removeMember(std::vector<Member>& members, std::string toRemove)
{
	auto found = findByName(members, toRemove);
=======
inline void SortedVector<Member>::addMember(Member newMemb)
{
	assert(findByName(newMemb.getName()) == members.end() && "Member with same name already present!\n");
	insertSorted(newMemb);
}
template <class Member>
inline void SortedVector<Member>::sort(Comparator compareBy)
{
	std::sort(members.begin(), members.end(),compareBy);
}
template <class Member>
inline void SortedVector<Member>::removeMember(std::string toRemove)
{
	auto found = findByName(toRemove);
>>>>>>> Stashed changes
	assert(found != members.end() && "No such member exists here!");
	members.erase(found);
}
template <class Member>
<<<<<<< Updated upstream
void SortedVector<Member>::print(std::vector<Member>& members, std::ostream& out)
=======
inline void SortedVector<Member>::print(std::ostream& out)const
>>>>>>> Stashed changes
{
	for (auto i : members) {
		i.print(out);
	}
}
<<<<<<< Updated upstream
=======
template <class Member>
inline size_t SortedVector<Member>::size() const{
	return members.size();
}

template<class Member>
inline void SortedVector<Member>::clear()
{
	members.clear();
}

template<class Member>
inline const Member& SortedVector<Member>::operator[](size_t position) const
{
	return members[position];
}

template<class Member>
inline Member& SortedVector<Member>::operator[](size_t position)
{
	return members[position];
}
>>>>>>> Stashed changes

#endif // !SORTED_VECTOR

