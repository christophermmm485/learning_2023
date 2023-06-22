#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initialize_students(struct Student* students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        students[i].rollno = 0;
        strncpy(students[i].name, "", sizeof(students[i].name));
        students[i].name[sizeof(students[i].name) - 1] = '\0';
        students[i].marks = 0.0;
    }
}

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    struct Student* students = (struct Student*)malloc(num_students * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    initialize_students(students, num_students);

    // Print the initialized array of structures
    printf("Initialized array of structures:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    free(students);
    return 0;
}
