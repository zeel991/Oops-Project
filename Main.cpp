#include <iostream>
#include "Question.h"
#include "Quiz.h"
#include "Account.h"

int main() {
    // Create a Quiz object
    Quiz quiz;

    // Create some student and teacher objects
    Student student1("Alice", 101, 85);
    Teacher teacher1("Mr. Smith", 202, "Mathematics");

    // Display student and teacher information
    student1.displayInfo();
    student1.displayRole();
    // student1.displayScore();

    cout << endl;

    teacher1.displayInfo();
    teacher1.displayRole();
    teacher1.displaySubject();

    cout << endl;

    // Take the quiz
    quiz.takeQuiz(&student1);

    return 0;
}