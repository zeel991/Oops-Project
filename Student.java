import java.util.Scanner;

public class Student extends Account {
    public Student(String name, String id) {
        super(name, id);
    }

    public void takeQuiz(Quiz quiz) {
        System.out.println("Starting Quiz: " + quiz.getName());
        Scanner scanner = new Scanner(System.in);
        int score = 0;

        for (Question question : quiz.getQuestions()) {
            question.displayQuestion();
            System.out.print("Your answer: ");
            int answer = scanner.nextInt();
            if (question.isCorrectAnswer(answer - 1)) {
                score++;
            }
        }

        System.out.println("Quiz Complete! Your score: " + score);
        quiz.recordScore(this, score);
    }

    @Override
    public void viewDashboard() {
        System.out.println("Student Dashboard");
    }
}
