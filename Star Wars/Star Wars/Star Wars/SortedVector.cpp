#include "SortedVector.h"
#include <algorithm>


//template <class Member>
//auto SortedVector<Member>::findByName(std::vector<Member>& members, std::string name)
//{
//	for (auto i = members.begin(); i != members.end();i++) {
//		if (i->getName() == name)return i;
//	}
//	return members.end();
//}
//template <class Member>
//void SortedVector<Member>::insertSorted(std::vector<Member>& members, Member newMemb)
//{
//	auto insertionPoint = std::upper_bound(members.begin(), members.end(), newMemb);
//	members.insert(insertionPoint, newMemb);
//}
//template <class Member>
//void SortedVector<Member>::addMember(std::vector<Member>& members, Member newMemb)
//{
//	assert(findByName(members, newMemb.getName()) == members.end());
//	insertSorted(members, newMemb);
//}
//template <class Member>
//void SortedVector<Member>::sort(std::vector<Member>& members)
//{
//	std::sort(members.begin(), members.end());
//}
//template <class Member>
//void SortedVector<Member>::removeMember(std::vector<Member>& members, std::string toRemove)
//{
//	auto found = findByName(members, toRemove);
//	assert(found != members.end() && "No such member exists here!");
//	members.erase(found);
//}
//template <class Member>
//void SortedVector<Member>::print(std::vector<Member>& members, std::ostream& out)
//{
//	for (auto i : members) {
//		i.print(out);
//	}
//}

