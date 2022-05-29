#include <vector>
#include <iostream>
#include "Planet.h"
//template <class NamedClass>
//class ContainerOfNamed {
//	std::vector<NamedClass> members;
//	auto findMember(std::string name) {
//		for (auto i = members.begin(); i != members.end();i++) {
//			if (i->getName() == name)return i;
//		}
//		return members.end();
//	}
//public:
//	void addMember(NamedClass newMember) {
//		assert(findMember(newMember.getName())==members.end() && "Member with the same name found!");
//		members.push_back(newMember);
//	}
//	void removeMember(std::string name) {
//		std::cout << "Eracing " << name<<'\n';
//		auto found = findMember(name);
//		assert(found != members.end() && "Member does not exist!");
//		members.erase(found);
//	}
//};
int main() {
	//ContainerOfNamed<Jedi> test;
	//test.addMember(Jedi{ "Somebody", "BATTLE_MASTER", 21, "purple",21 });
	//test.addMember(Jedi{ "", "BATTLE_MASTER", 21, "purple",21 });
	//test.removeMember("Somebody2");
	bool (*strongerJedi)(const Jedi*, const Jedi*) =
		[](const Jedi* lhs, const Jedi* rhs) {return lhs->getStrength() < rhs->getStrength(); };
	Planet testy{"Despacito"};
	Jedi test{ "Somebody", "BATTLE_MASTER", 21, "purple",21 };
	Jedi test2{ "Somebody2", "BATTLE_MASTER", 21, "purple",21 };
	testy.addMember(test);
	testy.addMember(test2);
	testy.print(std::cout);
	//std::cout << testy.getBestJediBy(strongerJedi);
	return 0;
}