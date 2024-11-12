#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
#include<sstream>
#include <vector>
#include<unordered_map>
using namespace std;
class Admin {
protected:
    string name;
    string password;

public:
    Admin(string n , string password) : name(n) , password(password){}

    virtual void displayRole() = 0;

    void displayInfo() {
        cout << "Name: " << name << endl;
    }

    string getName() const { return name; }

    virtual ~Admin() {}
};

class Student : public Admin {
private:
    string id;
    unordered_map<string , int> Quiz_Score;
public:
    Student(string n, int i, int s) : Admin(n, password) {}

    void displayRole() override {
        cout << "Role: Student" << endl;
    }

    void displayScore(string Quiz_code) {
        cout << "Score: " << Quiz_Score[Quiz_code] << endl;
    }
};

class Teacher : public Admin {
private:
    string subject;

public:
    Teacher(string n, int i, string sub) : Admin(n, password), subject(sub) {}

    void displayRole() override {
        cout << "Role: Teacher" << endl;
    }

    void displaySubject() {
        cout << "Subject: " << subject << endl;
    }
};

#endif // ACCOUNT_H