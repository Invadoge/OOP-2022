#pragma once
#include "Destination.h"


class User {
private:
    std::string username;
    //std::vector<Destination> visitedDes; Does not need to be used for current assignement
    //Private functions:
    bool validUsername(const std::string) const;
    std::string getUserAndPassword(const std::string) const;
public:
    std::string getUsername()const {
        return username;
    }
    void login();
    void registerUser();
    void getReviewsForDes(const std::string desName) const;
    void addReview() const;
    void displayLoggedUserReviews()const;
    void logout() {
        username.clear();
    }
    bool loggedIn() {
        return !username.empty();
    }
    void UserInterface();
};

inline bool User::validUsername(const std::string uName) const {
    if (uName.empty())return false;
    for (char c : uName) {
        if (!isLetter(c) && (c < '0' || c > '9'))return false;
    }
    return true;
}
std::string User::getUserAndPassword(const std::string uName) const {
    std::string result;
    std::ifstream userD;
    userD.open("userDatabase.txt");
    if (userD.is_open()) {
        while (std::getline(userD, result)) {
            if (result.find(uName) != std::string::npos) {
                break;
            }
            result.clear();
        }
        userD.close();
    }
    else {
        std::cerr << "Could not open userDatabase.txt\n";
    }
    return result;
}
void User::login() {
    std::string temp;
    std::string uAndPass;
    std::string tempUsername;
    std::fstream userD;
    size_t passPos;
    size_t passPos2;
    userD.open("userDatabase.txt");
    if (userD.is_open()) {
        userD.close();
    }
    else {
        std::cerr << "Database does not exist!\n";
        return;
    }
    unsigned tries = 3;

    std::cout << "Insert username here: ";
    std::getline(std::cin, temp);
    uAndPass = getUserAndPassword(temp);
    if (uAndPass.empty()) {
        std::cout << "This user is not registered!\n";
        return;
    }
    tempUsername = temp;
    for(unsigned i=0; i < tries; i++){
        std::cout << "Enter password(Tries remaining " << tries - i << "): ";
        std::getline(std::cin, temp);
        passPos = uAndPass.find(" ");
        passPos2 = uAndPass.substr(passPos+1).find(" ");
        if (uAndPass.substr(passPos + 1, passPos2) == temp) {
            username = tempUsername;
            break;
        }
    }
}
void User::registerUser() {
    std::string temp;
    std::string dataToWrite;//Safeguard for when the program ends abruptly
    unsigned tries = 0;//SO that the registration isn't eternal
    do {
        std::cout << "Enter username here: ";
        std::getline(std::cin, temp);
        tries++;
        if (!validUsername(temp)) {
            std::cout << "Username MUST contain only latin letters and numbers!\n";
            temp.clear();
        }
        else if (!getUserAndPassword(temp).empty()) {
            std::cout << "User already registered!\n";
            temp.clear();
        }
    } while (temp.empty() && tries < 3);
    if (tries >= 3)return;
    username = temp;
    dataToWrite = temp;
    std::ofstream userD;
    userD.open("userDatabase.txt", std::ios::app);
    if (userD.is_open()) {
        std::cout << "Enter password: ";
        std::getline(std::cin, temp);
        dataToWrite.append(" ");
        dataToWrite.append(temp);
        dataToWrite.append(" ");
        std::cout << "Enter email: ";
        std::getline(std::cin, temp);
        dataToWrite.append(temp);
        userD << dataToWrite << '\n';
        userD.close();
    }
    else {
        std::cerr << "Could not open userDatabase.txt\n";
    }
    
    temp = username;
    temp.append(".txt");
    userD.open(temp, std::ios::trunc);
    if (userD.is_open()) {
        userD << username << '\n';
        userD.close();
    }
    else {
        std::cerr << "Could not open personal user file!\n";
    }
}
void User::getReviewsForDes(const std::string desName)const {
    if (username.empty()) {
        std::cerr << "User not signed in!\n";
        return;
    }
    std::ifstream reviews;
    reviews.open("reviews.txt");
    std::string temp;
    int linesToread = 0;
    double averageGrade = 0;
    int gradecount = 0;
    if (reviews.is_open()) {
        while (std::getline(reviews, temp)) {
            if (temp[0] == 'b' && temp.find(desName) != std::string::npos) {
                gradecount++;
                averageGrade += temp[2] - '0';//this is where the grade is written
                linesToread = temp[1] - '0';//it should always be on the second place of the first line in a review its either 2 or 3
                std::cout << temp.substr(4) << '\n';//temp starts with string "b__ " which shouldn't be displayed
                for (int i = 0; i < linesToread; i++) {
                    std::getline(reviews, temp);
                    std::cout << temp << '\n';
                }
            }
        }
        std::cout << "Average grade for destination: " << averageGrade / gradecount << '\n';
        reviews.close();
    }
    else std::cerr << "Could not open reviews.txt!\n";
}
void User::addReview() const{
    if (username.empty()) {
        std::cerr << "User not signed in!\n";
        return;
    }
    Destination review;
    std::string temp;
    //Setting destination name
    std::cout << "Type destination name: ";
    std::getline(std::cin, temp);
    review.setDname(temp);
    //Setting destination grade
    short unsigned grade;
    do {
        std::cout << "Rate the destination(from 1 to 5): ";
        std::cin >> grade;
    } while (!review.setGrade(grade));
    //Setting destination dates
    Date from, to;
    int year;
    unsigned day, month;
    do {
        std::cout << "Write the date when you arrived(day month year): ";
        std::cin >> day >> month >> year;
        from.setDate(year, month, day);
        std::cout << "Write the date when you left(day month year): ";
        std::cin >> day >> month >> year;
        to.setDate(year, month, day);
    } while (!review.setFromTo(from, to));
    //Setting destination comment
    std::cout << "Would you like to add any description? Press Enter when you're ready. Type here: ";
    std::getline(std::cin >>std::ws, temp);
    review.setComment(temp);
    //Setting destination photos
    short unsigned photoCount = 0;
    std::cout << "How many photos would you like to add? Type here: ";
    std::cin >> photoCount;
    for (short unsigned i = 0; i < photoCount; i++) {
        do {
            std::cout << "Insert photo name: ";
            std::getline(std::cin>>std::ws, temp);
        } while (!review.addPhoto(temp));
    }
    
    //Adding review to user file
    std::ofstream os;
    temp = username;
    temp.append(".txt");
    os.open(temp, std::ios::app);
    if (os.is_open()) {
        os << review;
        os.close();
    }
    else std::cerr << "Could not open personal user file!\n";
    //Adding review to reviews file
    os.open("reviews.txt",std::ios::app);
    if (os.is_open()) {
        os << 'b'<< 1 + (bool)photoCount<< review.getGrade() <<" " << username << " " << review;
        os.close();
    }
    else std::cerr << "Could not open reviews file!\n";
}
void User::displayLoggedUserReviews() const{
    if (username.empty()) {
        std::cout << "User not signed in!\n";
        return;
    }
    std::ifstream userFile;
    std::string temp = username;
    temp.append(".txt");
    userFile.open(temp);
    while (std::getline(userFile, temp)) {
        std::cout << temp << '\n';
    }
}
void User::UserInterface() {
    std::string command;
    while (true) {
        std::cout << "Welcome to Traveler's Diary!\nPlease enter what you want to do(login/register/quit): ";
        std::getline(std::cin, command);
        if (command == "login")login();
        else if (command == "register")registerUser();
        else if (command == "quit")return;
        command.clear();
        if (loggedIn())std::cout << "\nWelcome " << getUsername() << "!\n";
        while (loggedIn()) {
            std::cout << "\nWhat would you want to do(add review/check profile/check reviews/logout/quit): ";
            std::getline(std::cin >> std::ws, command);
            if (command == "add review")addReview();
            else if (command == "check profile")displayLoggedUserReviews();
            else if (command == "check reviews") {
                std::cout << "Which destination do you want the reviews for: ";
                std::getline(std::cin >> std::ws, command);
                getReviewsForDes(command);
            }
            else if (command == "logout")logout();
            else if (command == "quit")return;
            command.clear();
        }
    }
}
