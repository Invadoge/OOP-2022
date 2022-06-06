#include <vector>
#include <iostream>
#include <fstream>
#include "Testing.h"
#include "Parser.h"
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
//struct Test {
//	static void operate(std::string* lhs, std::string* rhs) {
//		std::cin >> *lhs;
//		std::cin.ignore();
//		std::cin >> *rhs;
//		std::cin.ignore();
//	}
//};
int main() {
	/*std::string pesho;
	std::string pesho2;
	std::string pesho3;
	std::cin >> pesho;
	std::cin.ignore();
	if (pesho == "pesho") {
		std::cout << "Pesho is pesho!\n";
		Test::operate(&pesho2, &pesho3);
	}
	std::cout <<"Pesho:\n" << pesho << "\nPesho2:\n" << pesho2 << "\nPesho3:\n" << pesho3 << '\n';*/
	StarWars vanka;
	UserInterface vankata{ vanka, std::cin, std::cout };
	vankata.UI();
	return 0;
}