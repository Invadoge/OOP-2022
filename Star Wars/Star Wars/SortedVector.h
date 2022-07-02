#ifndef SORTED_VECTOR
#define SORTED_VECTOR
#include <vector>
#include <string>
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
	auto findByName(std::string)const;
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
{
	for (auto i = members.begin(); i != members.end(); i++) {
		if (i->getName() == name)return i;
	}
	return members.end();
}
template <class Member>
inline auto SortedVector<Member>::findByName(std::string name)const
{
	for (auto i = members.begin(); i != members.end(); i++) {
		if (i->getName() == name)return i;
	}
	return members.end();
}
template <class Member>
inline void SortedVector<Member>::insertSorted(Member newMemb)
{
	auto insertionPoint = std::upper_bound(members.begin(), members.end(), newMemb);
	members.insert(insertionPoint, newMemb);
}
template <class Member>
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
	assert(found != members.end() && "No such member exists here!");
	members.erase(found);
}
template <class Member>
inline void SortedVector<Member>::print(std::ostream& out)const
{
	for (auto i : members) {
		i.print(out);
	}
}
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

#endif // !SORTED_VECTOR

