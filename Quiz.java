import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Quiz {
    private static int quizCounter = 1000;
    private String name;
    private String testCode;
    private List<Question> questions;
    private static final String SCORE_FILE = "quiz_scores.txt";

    public Quiz(String name) {
        this.name = name;
        this.testCode = "QUIZ-" + (quizCounter++);
        this.questions = new ArrayList<>();
    }

    public String getTestCode() {
        return testCode;
    }

    public String getName() {
        return name;
    }

    public List<Question> getQuestions() {
        return questions;
    }

    public void addQuestion(Question question) {
        questions.add(question);
    }

    public void recordScore(Student student, int score) {
        try (FileWriter writer = new FileWriter(SCORE_FILE, true)) {
            writer.write("Student: " + student.getName() + ", Score: " + score + " in Quiz: " + name + "\n");
        } catch (IOException e) {
            System.out.println("Error writing score to file: " + e.getMessage());
        }
    }
}
