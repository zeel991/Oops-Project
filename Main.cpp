#include <iostream>
#include <vector>
#include "Question.h"
#include "Quiz.h"
#include "Account.h"
#include <algorithm> 
using namespace std;

int main() {
    vector<Quiz> quizzes;
    vector<Student> students;
    vector<Teacher> teachers;

    Student student1("Zeel", "hello", "BT23CSE116");
    students.push_back(student1);
    Teacher teacher1("Zeel", "1234", "Mathematics", "CSL102");
    teachers.push_back(teacher1);
    int choice = 1;
    while (choice) {
        cout<<endl;
        cout << " +-----------------------------------------------------+"<<endl;
        cout << " |           1: Login as a Student                     |" << endl;
        cout << " |           2: Login as a Teacher                     |"<< endl;
        cout << " |           3: Register as a Student                  |"<< endl;
        cout << " |           4: Register as a Teacher                  |" << endl;
        cout << " |           5: Exit                                   |" << endl;
        cout << " +-----------------------------------------------------+"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Student login
                string studentName, password;
                cout << "Enter Student Name: ";
                cin >> studentName;
                cout << "Enter Password: ";
                cin >> password;

                // Find the student in the list
                auto studentIt = find_if(students.begin(), students.end(), [&](Student& s) {
                    return s.getName() == studentName && s.getPassword() == password;
                });

                if (studentIt != students.end()) {
                    int ans;
                    cout<<endl;
                    cout <<"+-------------------+"<<endl;
                    cout <<"|1: Take Quiz       |" << endl;
                    cout <<"|2: View Score      |" << endl;
                    cout <<"+-------------------+"<<endl;
                    cout <<"Enter your choice: ";
                    cin >> ans;

                    if (ans == 1) {
                        string quizCode;
                        cout << "Enter the quiz code: ";
                        cin >> quizCode;

                        // Find quiz by quizCode
                        auto quizIt = find_if(quizzes.begin(), quizzes.end(), [&](Quiz& q) {
                            return q.getQuizCode() == quizCode;
                        });

                        if (quizIt != quizzes.end()) {
                            quizIt->takeQuiz(&(*studentIt));
                        } else {
                            cout << "Quiz not found or incorrect quiz code." << endl;
                        }
                    } else if (ans == 2) {
                        // Display score (implement score display if applicable)
                        cout << "Enter the quiz code to view score: ";
                        string quizCode;
                        cin >> quizCode;

                        cout << "Score: " << studentIt->getScore(quizCode) << endl;
                    }
                } else {
                    cout << "Student not found or incorrect credentials." << endl;
                }
                break;
            }
            case 2: { // Teacher login
                string teacherName, password;
                cout << "Enter Teacher Name: ";
                cin >> teacherName;
                cout << "Enter Password: ";
                cin >> password;

                // Find the teacher in the list
                auto teacherIt = find_if(teachers.begin(), teachers.end(), [&](Teacher& t) {
                    return t.getName() == teacherName && t.getPassword() == password;
                });

                if (teacherIt != teachers.end()) {
                    cout << "Make a new Quiz" << endl;
                    Quiz newQuiz;
                    quizzes.push_back(newQuiz);
                } else {
                    cout << "Teacher not found or incorrect credentials." << endl;
                }
                break;
            }
            case 3: { // Register as a Student
                string name, password, id;
                cout << "Enter Student Name: ";
                cin >> name;
                cout << "Enter Password: ";
                cin >> password;
                cout << "Enter Student ID: ";
                cin >> id;
                
                Student newStudent(name, password, id);
                students.push_back(newStudent);
                cout << "Student registered successfully." << endl;
                break;
            }
            case 4: { // Register as a Teacher
                string name, password, subject, courseCode;
                cout << "Enter Teacher Name: ";
                cin >> name;
                cout << "Enter Password: ";
                cin >> password;
                cout << "Enter Subject: ";
                cin >> subject;
                cout << "Enter Course Code: ";
                cin >> courseCode;

                Teacher newTeacher(name, password, subject, courseCode);
                teachers.push_back(newTeacher);
                cout << "Teacher registered successfully." << endl;
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                choice = 0;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    }

    return 0;
}
