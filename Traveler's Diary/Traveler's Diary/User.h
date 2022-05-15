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
    const std::string getUsername()const {
        return username;
    }
    void login();
    void registerUser();
    void getReviewsForDes(const std::string desName) const;
    void addReview() const;
    void displayLoggedUserInfo()const;
    void logout() {
        username.clear();
    }
    bool loggedIn() {
        return !username.empty();
    }
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
        std::cout << "Enter password: ";
        std::getline(std::cin, temp);
        if (uAndPass.find(temp) != std::string::npos) {
            username = tempUsername;
            break;
        }
    }
}
void User::registerUser() {
    std::string temp;
    do {
        std::cout << "Enter username here: ";
        std::getline(std::cin, temp);
        if (!validUsername(temp)) {
            std::cout << "\nUsername MUST contain only latin letters and numbers!\n";
            temp.clear();
        }
        else if (!getUserAndPassword(temp).empty()) {
            std::cout << "\nUser already registered!\n";
            temp.clear();
        }
    } while (temp.empty());
    username = temp;
    std::ofstream userD;
    userD.open("userDatabase.txt", std::ios::app);
    if (userD.is_open()) {
        userD << temp << " ";
        std::cout << "\nEnter password: ";
        std::getline(std::cin, temp);
        userD << temp << "\n";
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
    if (reviews.is_open()) {
        while (std::getline(reviews, temp)) {
            if (temp.find(desName) != std::string::npos) {
                //each valid review consists of 3 lines
                std::cout << temp << '\n';
                std::getline(reviews, temp);
                std::cout << temp << '\n';
                std::getline(reviews, temp);
                std::cout << temp << '\n';
            }
        }
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
        os << username << " " << review;
        os.close();
    }
    else std::cerr << "Could not open reviews file!\n";
}
void User::displayLoggedUserInfo() const{
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
