#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Date {
    int year;
    short unsigned month;
    short unsigned day;
    void setDate(const int myear,const short unsigned mmonth,const short unsigned mday) {
        year = myear;
        month = mmonth;
        day = mday;
    }
    int dateToInt()const {                           //very simplistic way for calculating the year
        return year * 365 + month * 30 + day;   //doesn't account for different months or leap years or B.C.
    }
    bool validMonth()const {
        return month > 0 && month <= 12;
    }
    bool validDay()const {
        if (day > 31 || day == 0)return false;
        switch (month) {
            case (4,6,9,11):
                return day <= 30;
                break;
            case 2:
                if (year % 4 == 0)return day <= 29;
                else return day <= 28;
            default:
                return true;
        }
    }
    friend int operator-(Date, Date);
    friend std::ostream& operator<<(std::ostream& fileName, const Date& dt);
};
int operator-(Date first, Date second) {
    return first.dateToInt() - second.dateToInt();
}
std::ostream& operator<<(std::ostream& fileName, const Date& dt) {
    fileName << dt.day << "-" << dt.month << "-" << dt.year;
    return fileName;
}

bool isLetter(const char symbol) {
    return symbol >= 'a' && symbol <= 'z' || symbol >= 'A' && symbol <= 'Z';
}//Function is also used in User.h for checking valid username

class Destination {
private:
    std::string dname;
    std::vector<std::string> photos;
    short unsigned grade=3;
    Date fromTo[2]; 
    std::string comment;
    //Private functions:
    bool validPhotoName(const std::string photoname) const{
        size_t pos = photoname.find(".");
        if (pos == std::string::npos)return false;

        std::string ext = photoname.substr(pos);
        if (ext != ".jpeg" && ext != ".png")return false;
        
        for (size_t i = 0; i < pos;i++) {
            if (!isLetter(photoname[i]) && photoname[i] != '_')return false;
        }
        return true;
    }
public:
    //Setters
    void setDname(const std::string newDname) {
        dname = newDname;
    }
    void setComment(const std::string newComment) {
        comment = newComment;
    }
    bool setGrade(const short unsigned newGrade) {//it is bool so that invalid grades can be handled however needed
        if (newGrade > 5) {
            grade = 5;
            return false;
        }
        else if (newGrade < 1) {
            grade = 1;
            return false;
        }
        grade = newGrade;
        return true;
    }
    bool addPhoto(const std::string photo) {
        if (!validPhotoName(photo)) {
            std::cerr << "Invalid photo name, did not add to destination photos!\n";
            return false;
        }
        photos.push_back(photo);
        return true;
    }
    bool setFromTo(const Date from,const Date to) {
        if (!from.validMonth() || !from.validDay()) {
            std::cerr << "Invalid from-date!\n";
            return false;
        }
        if (!to.validMonth() || !to.validDay()) {
            std::cerr << "Invalid to-date!\n";
            return false;
        }
        if (to - from < 0) {
            std::cerr << "To-date must be after from-date!\n";
            return false;
        }
        fromTo[0] = from;
        fromTo[1] = to;
        return true;
    }

    friend std::ostream& operator<<(std::ostream& filePlace, const Destination& des);
};
std::ostream& operator<<(std::ostream& filePlace, const Destination& des) {
    filePlace << des.dname << " " << des.grade << " " << des.fromTo[0] << " " << des.fromTo[1] << '\n';
    filePlace << des.comment <<'\n';
    size_t pLen = des.photos.size();
    for (size_t i = 0; i < pLen;i++) {
        if (i == pLen - 1)filePlace << des.photos[i] << "\n";
        else filePlace << des.photos[i] << " ";
    }
    return filePlace;
}