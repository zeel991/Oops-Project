import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Teacher teacher = new Teacher("Mr. Smith", "T001");
        Quiz quiz = teacher.createQuiz("Java Basics");

        // Teacher sets questions for the quiz
        Question q1 = new Question("What is the output of 2+2?", Arrays.asList("3", "4", "5"), 1);
        Question q2 = new Question("What is the type of 'Hello'?", Arrays.asList("int", "String", "bool"), 1);
        teacher.addQuestionToQuiz(quiz, q1);
        teacher.addQuestionToQuiz(quiz, q2);

        // Student takes the quiz
        Student student = new Student("Alice", "S001");
        student.takeQuiz(quiz);
    }
}
