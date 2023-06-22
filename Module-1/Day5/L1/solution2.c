#include <stdio.h>

// Structure to represent a complex number
struct Complex {
    float real;
    float imaginary;
};

// Function to read a complex number from the user
void readComplex(struct Complex* num) {
    printf("Enter the real part: ");
    scanf("%f", &(num->real));

    printf("Enter the imaginary part: ");
    scanf("%f", &(num->imaginary));
}

// Function to write a complex number to the console
void writeComplex(struct Complex num) {
    printf("Complex Number: %.2f + %.2fi\n", num.real, num.imaginary);
}

// Function to add two complex numbers
struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex sum;
    sum.real = num1.real + num2.real;
    sum.imaginary = num1.imaginary + num2.imaginary;
    return sum;
}

// Function to multiply two complex numbers
struct Complex multiplyComplex(struct Complex num1, struct Complex num2) {
    struct Complex product;
    product.real = (num1.real * num2.real) - (num1.imaginary * num2.imaginary);
    product.imaginary = (num1.real * num2.imaginary) + (num1.imaginary * num2.real);
    return product;
}

int main() {
    struct Complex num1, num2, sum, product;

    printf("Enter the first complex number:\n");
    readComplex(&num1);

    printf("\nEnter the second complex number:\n");
    readComplex(&num2);

    printf("\nFirst Complex Number:\n");
    writeComplex(num1);

    printf("\nSecond Complex Number:\n");
    writeComplex(num2);

    sum = addComplex(num1, num2);
    printf("\nSum of Complex Numbers:\n");
    writeComplex(sum);

    product = multiplyComplex(num1, num2);
    printf("\nProduct of Complex Numbers:\n");
    writeComplex(product);

    return 0;
}
