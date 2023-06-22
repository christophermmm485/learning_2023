#include <stdio.h>

#define DECIMAL_TO_BCD(num) (((num / 10) << 4) | (num % 10))

// Function to convert a decimal number to BCD format
unsigned char decimalToBCD(unsigned char decimal) {
    unsigned char tens = decimal / 10;
    unsigned char ones = decimal % 10;

    return (tens << 4) | ones;
}

int main() {
    unsigned char decimal = 32; // Example decimal number: 32

    // Using the preprocessor macro
    unsigned char bcdMacro = DECIMAL_TO_BCD(decimal);
    printf("BCD (using macro) of %d: 0x%02X\n", decimal, bcdMacro);

    // Using the function
    unsigned char bcdFunction = decimalToBCD(decimal);
    printf("BCD (using function) of %d: 0x%02X\n", decimal, bcdFunction);

    return 0;
}
