#include <stdio.h>

#define MAX_STUDENTS 50

struct Student {
    char name[50];
    int marks;
};

void readStudentDetails(struct Student* students, int numStudents) {
    printf("Enter details for each student:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &students[i].marks);
    }
}

void writeStudentDetails(const struct Student* students, int numStudents) {
    printf("Student Details:\n");
    printf("-----------------\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s, Marks: %d\n", students[i].name, students[i].marks);
    }
}

float computeAverageMarks(const struct Student* students, int numStudents) {
    int totalMarks = 0;
    for (int i = 0; i < numStudents; i++) {
        totalMarks += students[i].marks;
    }
    return (float)totalMarks / numStudents;
}

void printStudentsAboveAverage(const struct Student* students, int numStudents, float averageMarks) {
    printf("Students scoring above average marks:\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < numStudents; i++) {
        if (students[i].marks > averageMarks) {
            printf("Name: %s, Marks: %d\n", students[i].name, students[i].marks);
        }
    }
}

void printStudentsBelowAverage(const struct Student* students, int numStudents, float averageMarks) {
    printf("Students scoring below average marks:\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < numStudents; i++) {
        if (students[i].marks < averageMarks) {
            printf("Name: %s, Marks: %d\n", students[i].name, students[i].marks);
        }
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    readStudentDetails(students, numStudents);

    printf("\n");

    writeStudentDetails(students, numStudents);

    float averageMarks = computeAverageMarks(students, numStudents);
    printf("\nAverage Marks: %.2f\n", averageMarks);

    printf("\n");

    printStudentsAboveAverage(students, numStudents, averageMarks);

    printf("\n");

    printStudentsBelowAverage(students, numStudents, averageMarks);

    return 0;
}
