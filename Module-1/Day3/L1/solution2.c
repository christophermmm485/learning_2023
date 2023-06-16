#include <stdio.h>

void printBits(unsigned int num) {
    int size = sizeof(num) * 8;  // Number of bits in an unsigned int

    for (int i = size - 1; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }

    printf("\n");
}

int main() {
    unsigned int num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    printBits(num);

    return 0;
}
