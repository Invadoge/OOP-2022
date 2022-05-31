#include <vector>
#include <iostream>
#include <fstream>
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
	Planet tester{ "Penis" };
	Jedi test{ "Somebody", "BATTLE_MASTER", 21, "purple",21 };
	Jedi test2{ "Somebody2", "BATTLE_MASTER", 21, "purple",21 };
	tester.addMember(test);
	tester.addMember(test2);

	Planet tester2{ "Cock" };
	Jedi test3{ "Jennifer", "YOUNGLING", 34, "pink",45 };
	tester2.addMember(test3);
	Planet result = concatPlanet(tester, tester2);
	result.print(std::cout);
	//testy.print(std::cout);
	//testy.getBestJediBy(testy.strongerJedi).print(std::cout);
	//std::ofstream testy;
	//testy.open("Testy.txt");
	//tester.saveToFile(testy);
	//testy.close();
	//std::ifstream testy2;
	//testy2.open("Testy.txt");
	//tester.loadFromFile(testy2);
	//tester.print(std::cout);
	return 0;
}