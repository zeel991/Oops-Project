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
    cin.ignore();
getline(cin, question); 
cout << question << endl; 

for (int j = 0; j < 4; j++) {
    cout << "Enter Option " << j + 1 << "\n";
    getline(cin, opt); 
    options.push_back(opt);
    cout << "Option " << j + 1 << ": " << opt << endl;
}



        cout << "Enter the Index of Correct Option: ";
        cin >> ans;
        cin.ignore(); // Clear newline character
        
        questions1.push_back(MultipleChoiceQuestion(question,options,(int)ans));
        options.clear();

        questions1[0].printQuestion();
    }

    for (int i = 0; i < number_of_TF; i++) {
        string question;
        int ans;

        cout << "Enter the True/False question :\n";
        getline(cin, question);
        cin.ignore();
        cout << "Enter 1 if answer is True, 2 if answer is False\n";
        cin >> ans;
        cin.ignore(); // Clear newline character

        questions2.push_back(TrueFalseQuestion(question, (int)ans));
    }
}

void Quiz::takeQuiz(Student* student) {
    int score = 0;

    cout << "Starting the quiz...\n";
    cout << "Quiz Code: " << quizCode << "\n";

    // Iterate over multiple-choice questions
    for (int i = 0; i < number_of_MCQ; i++) {
        // cout << "\nQuestion " << i + 1 << ": " << questions1[i].getQuestion() << "\n";
        questions1[i].askQuestion(); // Display question with options

        int answer;
        cout << "Enter your answer (1 - 4): ";
        cin >> answer;

        if (questions1[i].checkAnswer(answer)) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Incorrect. The correct answer was option " << questions1[i].getCorrectOption() << ".\n";
        }
    }

    // Iterate over true/false questions
    for (size_t i = 0; i < questions2.size(); i++) {
        cout << "\nQuestion " << i + 1 + questions1.size() << ": " << questions2[i].getQuestion() << "\n";
        questions2[i].askQuestion(); // Display true/false question

        int answer;
        cout << "Enter your answer (1 for True, 2 for False): ";
        cin >> answer;

        if (questions2[i].checkAnswer(answer)) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Incorrect. The correct answer was " 
                 << (questions2[i].getCorrectOption() == 1 ? "True" : "False") << ".\n";
        }
    }

    cout << "\nQuiz finished! Your score: " << score << " out of " 
         << (questions1.size() + questions2.size()) << "\n";
    // Save the score in the student's record (if implemented)
    student->setScore(quizCode, score);

    string filename = quizCode+"_results.txt";

    ofstream Write_Result;

    Write_Result.open(filename,ios::app);
    student->getScore(quizCode);
    Write_Result << "+----------------------------------------------+"<<endl;
    Write_Result << "|" +student->getID()<<"      |                     ";      
    Write_Result << student->getScore(quizCode)<<"       |"<<endl;
    Write_Result.close();

}
