#include "User.h"

void UserInterface(User& user) {
	std::string command;
	while (true) {
		std::cout << "Welcome to Traveler's Diary!\nPlease enter what you want to do(login/register/quit): ";
		std::getline(std::cin, command);
		if (command == "login")user.login();
		else if (command == "register")user.registerUser();
		else if (command == "quit")return;
		command.clear();
		if(user.loggedIn())std::cout << "\nWelcome " << user.getUsername() << "!\n";
		while (user.loggedIn()) {
			std::cout << "\nWhat would you want to do(add review/check profile/check reviews/logout/quit): ";
			std::getline(std::cin>>std::ws, command);
			if (command == "add review")user.addReview();
			else if (command == "check profile")user.displayLoggedUserInfo();
			else if (command == "check reviews") {
				std::cout << "Which destination do you want the reviews for: ";
				std::getline(std::cin>>std::ws, command);
				user.getReviewsForDes(command);
			}
			else if (command == "logout")user.logout();
			else if (command == "quit")return;
			command.clear();
		}
	}
}
int main()
{
	User user;
	UserInterface(user);
	return 0;
}
