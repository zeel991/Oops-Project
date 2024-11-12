#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

#include <iostream>
#include <string>
#include<sstream>
#include <vector>
class Admin {
protected:
    string name;
    int id;

public:
    Admin(string n, int i) : name(n), id(i) {}

    virtual void displayRole() = 0;

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }

    string getName() const { return name; }

    virtual ~Admin() {}
};

class Student : public Admin {
private:
    int score;

public:
    Student(string n, int i, int s) : Admin(n, i), score(s) {}

    void displayRole() override {
        cout << "Role: Student" << endl;
    }

    void displayScore() {
        cout << "Score: " << score << endl;
    }
};

class Teacher : public Admin {
private:
    string subject;

public:
    Teacher(string n, int i, string sub) : Admin(n, i), subject(sub) {}

    void displayRole() override {
        cout << "Role: Teacher" << endl;
    }

    void displaySubject() {
        cout << "Subject: " << subject << endl;
    }
};

#endif // ACCOUNT_H