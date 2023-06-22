#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};

struct Person* createPerson(const char* name, int age) {
    struct Person* newPerson = (struct Person*)malloc(sizeof(struct Person));
    if (newPerson != NULL) {
        strcpy(newPerson->name, name);
        newPerson->age = age;
    }
    return newPerson;
}

void displayPerson(const struct Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

void freePerson(struct Person* person) {
    free(person);
}

int main() {
    const char* name = "John";
    int age = 25;

    struct Person* person = createPerson(name, age);
    if (person != NULL) {
        displayPerson(person);
        freePerson(person);
    } else {
        printf("Failed to create person.\n");
    }

    return 0;
}
