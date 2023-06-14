#include <stdio.h>

int isVowel(char c) {
    /*
    This function takes a character as input and returns 1 if it is a vowel, 0 otherwise.
    
    Parameters:
    c (char): The character to be checked
    
    Returns:
    int: 1 if the character is a vowel, 0 otherwise
    */
    switch(c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return 1;
        default:
            return 0;
    }
}

int main() {
    char c = 'a';
    int result = isVowel(c);
    if (result == 1) {
        printf("Vowel");
    } else {
        printf("Not Vowel");
    }
    return 0;
}