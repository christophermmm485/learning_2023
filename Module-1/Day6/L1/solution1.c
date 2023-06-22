#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parse_input_string(const char* input_string, struct Student* students, int num_students) {
    char* token;
    char* rest = (char*)input_string;
    int i = 0;

    while ((token = strtok_r(rest, " ", &rest))) {
        if (i >= num_students) {
            printf("Exceeded the number of students provided.\n");
            return;
        }

        switch (i) {
            case 0:
                students[i].rollno = atoi(token);
                break;
            case 1:
                strncpy(students[i].name, token, sizeof(students[i].name) - 1);
                students[i].name[sizeof(students[i].name) - 1] = '\0';
                break;
            case 2:
                students[i].marks = atof(token);
                break;
            default:
                break;
        }

        i++;
    }
}

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    getchar();  // Consume the newline character

    struct Student* students = (struct Student*)malloc(num_students * sizeof(struct Student));

    printf("Enter the input string: ");
    char input_string[100];
    fgets(input_string, sizeof(input_string), stdin);
    input_string[strcspn(input_string, "\n")] = '\0';  // Remove the trailing newline character

    parse_input_string(input_string, students, num_students);

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
