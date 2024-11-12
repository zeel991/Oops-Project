#include <iostream>
#include <string>
#include <vector>
#include "Leaderboard.h"
#include "Question.cpp" // Include the question class

using namespace std;

class Quiz {
protected:
    int number_of_MCQ;
    int number_of_TF;
    string quizCode;
    vector<Question*> questions; // Use pointers to Question objects
public:
    Quiz() {
        cout << "Set the quiz code: ";
        cin >> quizCode;
        cin.ignore(); // Clear newline character after cin >> quizCode

        cout << "Enter the number of MCQ type questions: ";
        cin >> number_of_MCQ;
        cin.ignore(); // Clear newline character after cin >> number_of_MCQ

        cout << "Enter the number of TF type questions: ";
        cin >> number_of_TF;
        cin.ignore(); // Clear newline character after cin >> number_of_TF

        Insert_Questions();
    }

    // Insert questions to the quiz
    void Insert_Questions() {
        for (int i = 0; i < number_of_MCQ; i++) {
            string question;
            vector<string> options;
            int ans;

            cout << "Enter the MCQ question: ";
            cin.ignore(); // Clear newline character before getline
            getline(cin, question);

            for (int j = 0; j < 4; j++) {
                string opts;
                cout << "Enter option " << j + 1 << ": ";
                cin.ignore(); // Clear newline character before getline
                getline(cin, opts);
                options.push_back(opts);
            }

            cout << "Enter the index of the correct option: ";
            cin >> ans;
            questions.push_back(new MultipleChoiceQuestion(question, options, ans));
        }

        for (int i = 0; i < number_of_TF; i++) {
            string question;
            int ans;

            cout << "Enter the True/False question: ";
            cin.ignore(); // Clear newline character before getline
            getline(cin, question);

            cout << "Enter 1 for True or 2 for False: ";
            cin >> ans;
            questions.push_back(new TrueFalseQuestion(question, ans));
        }
    }

    // Grade the quiz and calculate the score
    int gradeQuiz() {
        int score = 0;
        int answer;

        for (Question* q : questions) {
            q->askQuestion();
            cout << "Enter your answer: ";
            cin >> answer;
            if (q->checkAnswer(answer)) {
                score++;
            }
        }
        return score;
    }

    ~Quiz() {
        for (Question* q : questions) {
            delete q;
        }
    }
};