#include <vector>
#include <iostream>
#include <fstream>
#include "Testing.h"
#include "Parser.h"
int main() {
	StarWars vanka;
	UserInterface vankata{ vanka, std::cin, std::cout };
	vankata.UI();
	return 0;
}