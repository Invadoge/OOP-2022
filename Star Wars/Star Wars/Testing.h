#ifndef STAR_WARS_TESTS
#define STAR_WARS_TESTS
#include "StarWars.h"
#include <iostream>
struct TestPlanets {
	static void testConcatenation();
	static void testLightSaberSearch();
};

inline void TestPlanets::testConcatenation()
{
	Planet tester{ "Pineapple" };
	Jedi test{ "Padme", "INITIATE", 21, "purple",21 };
	Jedi test2{ "Obi-Wan", "GRAND_MASTER", 21, "purple",21 };
	tester.addMember(test);
	tester.addMember(test2);
	std::cout << "First planet:\n";
	tester.print(std::cout);

	Planet tester2{ "Pizza" };
	Jedi test3{ "Jennifer", "YOUNGLING", 34, "pink",45 };
	tester2.addMember(test3);
	std::cout << "\nSecond planet:\n";
	tester2.print(std::cout);

	Planet result = concatPlanet(tester, tester2);
	std::cout << "\nCombined planet:\n";
	result.print(std::cout);
}
inline void TestPlanets::testLightSaberSearch()
{
	Planet tester{ "Lightsaby" };
	Jedi test{ "Padme", "INITIATE", 21, "purple",21 };
	Jedi test2{ "Obi-Wan", "GRAND_MASTER", 21, "green",21 };
	Jedi test3{ "Henry", "INITIATE", 21, "purple",21 };
	Jedi test4{ "Harry", "INITIATE", 21, "pink",21 };
	Jedi test5{ "Padme2", "INITIATE", 21, "black",21 };
	Jedi test6{ "Obi-Wan2", "GRAND_MASTER", 21, "grey",21 };
	tester.addMember(test);
	tester.addMember(test2);
	tester.addMember(test3);
	tester.addMember(test4);
	tester.addMember(test5);
	tester.addMember(test6);
	std::cout << "Planet: ";
	tester.print(std::cout);
	std::cout << "Most common lightsaber: ";
	std::cout << tester.getMostFrequentLightSaber("INITIATE");
}

struct TestStarWars {
	static void testFindJedi();
};

inline void TestStarWars::testFindJedi(){
	StarWars tester;
	tester.addPlanet("Cheese");
	tester.addPlanet("Moon");
	tester.addJedi("Cheese", { "Padme", "INITIATE", 21, "purple", 21 });
	tester.addJedi("Cheese", { "Jennifer", "YOUNGLING", 34, "pink",45 });
	tester.addJedi("Moon", { "Harry", "INITIATE", 21, "pink",21 });

	tester.findJedi("Harry")->print(std::cout);
}
#endif // !STAR_WARS_TESTS
