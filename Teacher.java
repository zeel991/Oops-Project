import java.util.ArrayList;
import java.util.List;

public class Teacher extends Account {
    private List<Quiz> quizzes;

    public Teacher(String name, String id) {
        super(name, id);
        this.quizzes = new ArrayList<>();
    }

    public Quiz createQuiz(String quizName) {
        Quiz quiz = new Quiz(quizName);
        quizzes.add(quiz);
        System.out.println("Quiz created with code: " + quiz.getTestCode());
        return quiz;
    }

    public void addQuestionToQuiz(Quiz quiz, Question question) {
        quiz.addQuestion(question);
    }

    @Override
    public void viewDashboard() {
        System.out.println("Teacher Dashboard");
    }
}
