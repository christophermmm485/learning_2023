#include <stdio.h>

// Function to set a bit at a given position
unsigned char setBit(unsigned char num, int pos) {
    unsigned char mask = 1 << pos;
    return num | mask;
}

// Function to clear a bit at a given position
unsigned char clearBit(unsigned char num, int pos) {
    unsigned char mask = ~(1 << pos);
    return num & mask;
}

// Function to toggle a bit at a given position
unsigned char toggleBit(unsigned char num, int pos) {
    unsigned char mask = 1 << pos;
    return num ^ mask;
}

int main() {
    unsigned char num = 0x37; // Example 8-bit number: 0011 0111

    printf("Original number: 0x%02X\n", num);

    // Set bit at position 3
    unsigned char setBitNum = setBit(num, 3);
    printf("After setting bit at position 3: 0x%02X\n", setBitNum);

    // Clear bit at position 5
    unsigned char clearBitNum = clearBit(num, 5);
    printf("After clearing bit at position 5: 0x%02X\n", clearBitNum);

    // Toggle bit at position 2
    unsigned char toggleBitNum = toggleBit(num, 2);
    printf("After toggling bit at position 2: 0x%02X\n", toggleBitNum);

    return 0;
}
