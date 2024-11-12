#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "Leaderboard.h"  // Include the leaderboard class

using namespace std;

class Student {
private:
    string name;  // Store the student's name
    int id;       // Store the student's ID
    int score;    // Store the student's score

public:
    // Constructor to initialize name, id, and score
    Student(string n, int i) : name(n), id(i), score(0) {}

    // Method to set the score after grading the quiz
    void setScore(int s) {
        score = s;
    }

    // Method to get the score
    int getScore() {
        return score;
    }

    // Display student information
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Score: " << score << endl;
    }

    // Add the student’s score to the leaderboard
    void updateLeaderboard() {
        Leaderboard leaderboard;
        leaderboard.addScore(name, score);  // Use the student's name and score
    }

    // Display the student's role
    void displayRole() {
        cout << "Role: Student" << endl;
    }
};

#endif // STUDENT_H