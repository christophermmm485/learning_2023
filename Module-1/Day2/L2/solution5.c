#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(char *str, int key) {
    int i;
    char ch;
    
    for (i = 0; str[i] != '\0'; i++) {
        ch = str[i];
        
        if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + key) % 26) + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + key) % 26) + 'A';
        }
        
        str[i] = ch;
    }
}

void decode(char *str, int key) {
    encode(str, 26 - key);
}

int main() {
    char str[100];
    int key;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    printf("Enter the key for encoding: ");
    scanf("%d", &key);
    
    // Remove the newline character from fgets
    str[strcspn(str, "\n")] = '\0';
    
    printf("\nOriginal string: %s\n", str);
    
    // Encode the string
    encode(str, key);
    printf("Encoded string: %s\n", str);
    
    // Decode the string
    decode(str, key);
    printf("Decoded string: %s\n", str);
    
    return 0;
}
