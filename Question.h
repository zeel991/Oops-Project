#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <string>
#include<sstream>
#include <vector>
using namespace std;


class Question {
protected:
    string questionText;
    vector<string> options;
    int correctAnswer; // index of correct answer

public:
    // to display the question,explained in derived classes
    virtual void askQuestion() = 0;

    // to check the answer is correct or not,explained in derived classes
    virtual bool checkAnswer(int answer) = 0;

    virtual ~Question() {}

};

class MultipleChoiceQuestion : public Question {
public:
    // constructor
    MultipleChoiceQuestion(string qText, vector<string> opts, int correctAns) {
        questionText = qText;
        options = opts;
        this->correctAnswer = correctAns;
    }

    // Displays the MCQ's with opts
    void askQuestion() override{
        cout << questionText << endl;
    for (int i = 0; i < options.size(); ++i) {
        cout << i + 1 << ". " << options[i] << endl;
    }
    };

    string getQuestion() {
        return this->questionText;
    }

    void printQuestion() {
        cout<< questionText<< endl;
        for(int i = 0;i< options.size();i++){
            cout<< options[i]<<endl;
        }
        cout<< correctAnswer<<endl;
    }
    // to Checks the correct an0swer
    bool checkAnswer(int answer) override;
    int getCorrectOption(){
        return correctAnswer;
    }
    vector<string> getOptions(){
        return options;
    }
};

// Derived class for true/false questions
class TrueFalseQuestion : public Question {
public:
    // Constructor to initialize the question text and correct answer (1 for True, 2 for False)
    TrueFalseQuestion(string qText, int correctAns) {
        questionText = qText;
        correctAnswer = correctAns;
    }

    // Displays the true/false question with options 1 for True and 2 for False
    void askQuestion() override;
 string getQuestion() {
        return this->questionText;
    }
    // Checks if the selected answer matches the correct answer
    bool checkAnswer(int answer) override;
        int getCorrectOption(){
        return correctAnswer;
    }
};

#endif // QUESTION_H