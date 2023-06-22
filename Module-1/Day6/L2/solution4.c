#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void rotate_array(struct Student* students, int num_students, int k) {
    if (k < 0) {
        printf("Invalid rotation value.\n");
        return;
    }

    // Calculate the effective rotation value within the range of num_students
    k = k % num_students;

    // Allocate temporary memory for rotated elements
    struct Student* temp = (struct Student*)malloc(k * sizeof(struct Student));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Copy the last k elements to the temporary array
    memcpy(temp, &students[num_students - k], k * sizeof(struct Student));

    // Shift the remaining elements to the right by k positions
    memmove(&students[k], students, (num_students - k) * sizeof(struct Student));

    // Copy the rotated elements from the temporary array to the beginning
    memcpy(students, temp, k * sizeof(struct Student));

    // Free the temporary memory
    free(temp);
}
