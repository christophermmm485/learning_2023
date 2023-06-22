#include <stdio.h>

void swapAlternate(int arr[], int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {10, 20, 30, 40, 50};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("Original array:\n");
    displayArray(arr1, size1);

    swapAlternate(arr1, size1);

    printf("Array after swapping alternate elements:\n");
    displayArray(arr1, size1);

    printf("\n");

    int arr2[] = {10, 20, 30, 40, 50, 60};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("Original array:\n");
    displayArray(arr2, size2);

    swapAlternate(arr2, size2);

    printf("Array after swapping alternate elements:\n");
    displayArray(arr2, size2);

    return 0;
}
