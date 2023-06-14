#include <stdio.h>

int bit_operations(int num, int oper_type, int pos) {
    switch (oper_type) {
        case 1: // Set 2 bits from nth bit position
            num |= (0x3 << pos);
            break;
        case 2: // Clear 3 bits from nth bit position
            num &= ~(0x7 << pos);
            break;
        case 3: // Toggle MSB
            num ^= (1 << 31);
            break;
    }
    return num;
}

int main() {
    int num, oper_type, pos;
    printf("Enter an integer (32 bits): ");
    scanf("%d", &num);
    printf("Enter the operation type (1: Set bits, 2: Clear bits, 3: Toggle MSB): ");
    scanf("%d", &oper_type);
    printf("Enter the position: ");
    scanf("%d", &pos);

    int result = bit_operations(num, oper_type, pos);

    printf("Result: %d\n", result);

    return 0;
}
