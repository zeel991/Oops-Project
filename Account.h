#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include<unordered_map>
using namespace std;
class Admin {
protected:
    string name;
    string password;

public:
    Admin(string n , string password) {}

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
    Student(string n, string password ,string id) : Admin(n, password) {
        this->name = n;
        this->password = password;
        this->id = id; 
    }

    void displayRole() override {
        cout << "Role: Student" << endl;
    }
    string getPassword(){
        return this->password;
    }
    int getScore(string Quiz_code) {
        cout << "Score: " << Quiz_Score[Quiz_code] << endl;
        return Quiz_Score[Quiz_code];
    }
};

class Teacher : public Admin {
private:
    string subject;
    string id;

public:
    Teacher(string n, string password, string sub ,string id) : Admin(n, password), subject(sub) {
        this->name = n;
        this->password = password;
        this->id = id;
        this->subject = sub;
    }
    string getPassword(){
        return this->password;
    }

    void displayRole() override {
        cout << "Role: Teacher" << endl;
        cout<< "Name :" <<endl;
        cout<< "ID" <<endl;
    }

    void displaySubject() {
        cout << "Subject: " << subject << endl;
    }
};

#endif // ACCOUNT_H