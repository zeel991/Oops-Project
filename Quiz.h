#ifndef QUIZ_H
#define QUIZ_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Question.h"
#include "Account.h"
using namespace std;

class Quiz {
protected:
    int number_of_MCQ;
    int number_of_TF;
    string quizCode;
    vector<MultipleChoiceQuestion> questions1; 
    vector<TrueFalseQuestion> questions2; 

public: 
    Quiz() {
    cout << "Set the quizcode\n";
    cin.ignore(); 
    getline(cin, quizCode); 

        cout << "Enter the number of MCQ type questions\n";
        cin >> number_of_MCQ;

        cout << "Enter the number of TF type questions\n";
        cin >> number_of_TF;

        insertQuestions();
        ofstream file(quizCode+"_results.txt");
    }

    void insertQuestions();

    string getQuizCode();

    void takeQuiz(Student* student);

    void storeQuizResult(const string& studentId, int score);
};

#endif // QUIZ_H