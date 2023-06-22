#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

// Custom comparison function for sorting in descending order based on marks
int compare_students(const void* a, const void* b) {
    const struct Student* student_a = (const struct Student*)a;
    const struct Student* student_b = (const struct Student*)b;

    if (student_a->marks < student_b->marks) {
        return 1;
    } else if (student_a->marks > student_b->marks) {
        return -1;
    } else {
        return 0;
    }
}

void display_students(const struct Student* students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
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

    // Initialize students here...

    // Sort the array of structures in descending order based on marks
    qsort(students, num_students, sizeof(struct Student), compare_students);

    printf("Sorted array of structures:\n");
    display_students(students, num_students);

    free(students);
    return 0;
}
