int main() {
    int num_students = 4;

    struct Student* students = (struct Student*)malloc(num_students * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize the array of structures here...

    int index1, index2;
    printf("Enter the indices of the members to swap (0 to %d): ", num_students - 1);
    scanf("%d %d", &index1, &index2);

    swap_members(students, num_students, index1, index2);

    // Display the updated array of structures
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
