#include <stdio.h>

int compareBoxes(int boxA[], int boxB[], int size) {
    int i, j;
    int found;

    for (i = 0; i < size; i++) {
        found = 0;

        for (j = 0; j < size; j++) {
            if (boxA[i] == boxB[j]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int boxA[] = {200, 10, -90};
    int boxB[] = {-90, 200, 10};
    int size = sizeof(boxA) / sizeof(boxA[0]);

    int result = compareBoxes(boxA, boxB, size);

    if (result == 1) {
        printf("The boxes have a one-to-one mapping of items.\n");
    } else {
        printf("The boxes do not have a one-to-one mapping of items.\n");
    }

    return 0;
}
