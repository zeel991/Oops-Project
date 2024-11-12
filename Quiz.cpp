#include "Quiz.h"
string Quiz::getQuizCode(){
    return this->quizCode;
}
void Quiz::insertQuestions() {
    vector<string> options;
    for (int i = 0; i < number_of_MCQ; i++) {
        string question;
        string opt;
        int ans;

         cout << "Enter the MCQ question " << i + 1 << "\n";
        cin.ignore(); // Ignore any newline left from previous input
        getline(cin, question); // Now read the full question line

        for (int j = 0; j < 4; j++) {
            cout << "Enter the Option " << j + 1 << "\n";
            cin >> opt;
            options.push_back(opt);
            cin.ignore(); // Clear newline character
        }

        cout << "Enter the Index of Correct Option: ";
        cin >> ans;
        cin.ignore(); // Clear newline character

        questions1.emplace_back(question, options, ans);
        options.clear();
    }

    for (int i = 0; i < number_of_TF; i++) {
        string question;
        int ans;

        cout << "Enter the True/False question :\n";
        getline(cin, question);

        cout << "Enter 1 if answer is True, 2 if answer is False\n";
        cin >> ans;
        cin.ignore(); // Clear newline character

        questions2.emplace_back(question, ans);
    }
}

void Quiz::takeQuiz(Student* student) {
    // Implement quiz taking logic here
    cout << "Student " << student->getName() << " is taking the quiz." << endl;
}