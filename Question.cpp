#include "Question.h"



bool MultipleChoiceQuestion::checkAnswer(int answer) {
    return answer == correctAnswer;
}


void TrueFalseQuestion::askQuestion() {
    cout << questionText << "\n1. True\n2. False" << endl;
}

bool TrueFalseQuestion::checkAnswer(int answer) {
    return answer == correctAnswer;
}

