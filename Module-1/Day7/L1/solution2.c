#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to convert text to upper case
void convertToUpper(FILE *source, FILE *destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(toupper(ch), destination);
    }
}

// Function to convert text to lower case
void convertToLower(FILE *source, FILE *destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(tolower(ch), destination);
    }
}

// Function to convert text to sentence case
void convertToSentenceCase(FILE *source, FILE *destination) {
    int ch;
    int previousChar = '.';
    while ((ch = fgetc(source)) != EOF) {
        if (previousChar == '.' || previousChar == '?' || previousChar == '!') {
            fputc(toupper(ch), destination);
        } else {
            fputc(tolower(ch), destination);
        }
        previousChar = ch;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [option] <source_file> <destination_file>\n", argv[0]);
        printf("Options:\n");
        printf("-u\tChange file content to upper case\n");
        printf("-l\tChange file content to lower case\n");
        printf("-s\tChange file content to sentence case\n");
        return 1;
    }

    FILE *sourceFile, *destinationFile;
    char *option = argv[1];
    char *sourceFileName = argv[2];
    char *destinationFileName = argv[3];
    char ch;

    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        return 1;
    }

    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Failed to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    if (strcmp(option, "-u") == 0) {
        convertToUpper(sourceFile, destinationFile);
    } else if (strcmp(option, "-l") == 0) {
        convertToLower(sourceFile, destinationFile);
    } else if (strcmp(option, "-s") == 0) {
        convertToSentenceCase(sourceFile, destinationFile);
    } else {
        // Normal copy
        while ((ch = fgetc(sourceFile)) != EOF) {
            fputc(ch, destinationFile);
        }
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
