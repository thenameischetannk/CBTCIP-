#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 10

typedef struct {
    char name[50];
    int scores[MAX_SUBJECTS];
    int num_subjects;
} Student;

void input_student_info(Student *student) {
    printf("Enter student name: ");
    scanf("%s", student->name);

    printf("Enter number of subjects: ");
    scanf("%d", &student->num_subjects);

    printf("Enter subject scores:\n");
    for (int i = 0; i < student->num_subjects; i++) {
        scanf("%d", &student->scores[i]);
    }
}

double calculate_average(Student student) {
    int sum = 0;
    for (int i = 0; i < student.num_subjects; i++) {
        sum += student.scores[i];
    }
    return (double)sum / student.num_subjects;
}

int find_highest_score(Student student) {
    int max = student.scores[0];
    for (int i = 1; i < student.num_subjects; i++) {
        if (student.scores[i] > max) {
            max = student.scores[i];
        }
    }
    return max;
}

int find_lowest_score(Student student) {
    int min = student.scores[0];
    for (int i = 1; i < student.num_subjects; i++) {
        if (student.scores[i] < min) {
            min = student.scores[i];
        }
    }
    return min;
}

void print_student_summary(Student student) {
    printf("\nStudent Summary:\n");
    printf("Name: %s\n", student.name);
    printf("Average Score: %.2f\n", calculate_average(student));
    printf("Highest Score: %d\n", find_highest_score(student));
    printf("Lowest Score: %d\n", find_lowest_score(student));
}

int main() {
    Student students[MAX_STUDENTS];
    int num_students;

    printf("Enter number of students: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_students; i++) {
        input_student_info(&students[i]);
    }

    for (int i = 0; i < num_students; i++) {
        print_student_summary(students[i]);
    }

    return 0;
}