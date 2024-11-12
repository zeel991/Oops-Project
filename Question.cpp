#include "Question.h"

void MultipleChoiceQuestion::askQuestion() {
    
    cout << questionText << endl;
    for (int i = 0; i < options.size(); ++i) {
        cout << i + 1 << ". " << options[i] << endl;
    }
}

bool MultipleChoiceQuestion::checkAnswer(int answer) {
    return answer == correctAnswer;
}

string MultipleChoiceQuestion::toFileFormat() {
    ostringstream oss;
    oss << "MCQ\n"
        << questionText << "\n"
        << options.size() << "\n";
    for (const string& option : options) {
        oss << option << "\n";
    }
    oss << correctAnswer << "\n---\n"; // for separation of questions
    return oss.str();
}

void TrueFalseQuestion::askQuestion() {
    cout << questionText << "\n1. True\n2. False" << endl;
}

bool TrueFalseQuestion::checkAnswer(int answer) {
    return answer == correctAnswer;
}

string TrueFalseQuestion::toFileFormat() {
    return "TF\n" + questionText + "\n" + to_string(correctAnswer) + "\n---\n"; // Adds delimiter for parsing
}