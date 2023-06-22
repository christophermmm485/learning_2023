#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
} LogEntry;

// Function to extract each line in the CSV file and store it in an array of structures
int readLogFile(LogEntry logEntries[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char *token;
    int entryCount = 0;

    file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the log file.\n");
        return -1;
    }

    // Read each line in the CSV file
    while (fgets(line, sizeof(line), file) != NULL && entryCount < MAX_ENTRIES) {
        // Tokenize the line based on commas
        token = strtok(line, ",");
        
        // Extract the values and store them in the log entry structure
        logEntries[entryCount].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strncpy(logEntries[entryCount].sensorNo, token, sizeof(logEntries[entryCount].sensorNo));

        token = strtok(NULL, ",");
        logEntries[entryCount].temperature = atof(token);

        token = strtok(NULL, ",");
        logEntries[entryCount].humidity = atoi(token);

        token = strtok(NULL, ",");
        logEntries[entryCount].light = atoi(token);

        token = strtok(NULL, ",");
        strncpy(logEntries[entryCount].time, token, sizeof(logEntries[entryCount].time));

        entryCount++;
    }

    fclose(file);
    return entryCount;
}

// Function to display the contents of the array of structures
void displayLogEntries(LogEntry logEntries[], int entryCount) {
    int i;
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTime\n");
    for (i = 0; i < entryCount; i++) {
        printf("%d\t%s\t\t%.2f\t\t%d\t\t%d\t%s\n",
               logEntries[i].entryNo,
               logEntries[i].sensorNo,
               logEntries[i].temperature,
               logEntries[i].humidity,
               logEntries[i].light,
               logEntries[i].time);
    }
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int entryCount;

    entryCount = readLogFile(logEntries);
    if (entryCount == -1) {
        return 1;
    }

    displayLogEntries(logEntries, entryCount);

    return 0;
}
