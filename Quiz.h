#ifndef QUIZ_H
#define QUIZ_H

#include <iostream>
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
        getline(cin, quizCode);

        cout << "Enter the number of MCQ type questions\n";
        cin >> number_of_MCQ;

        cout << "Enter the number of TF type questions\n";
        cin >> number_of_TF;

        insertQuestions();
    }

    void insertQuestions();

    void takeQuiz(Student* student);
};

#endif // QUIZ_H