#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_ENTRIES 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
} LogEntry;

// Function to update an entry in the data file
void updateEntry(LogEntry logEntries[], int entryCount, int entryNo, float temperature, int humidity, int light) {
    FILE *file;
    int i;

    file = fopen("data.csv", "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    // Write the updated entries to the file
    for (i = 0; i < entryCount; i++) {
        if (logEntries[i].entryNo == entryNo) {
            logEntries[i].temperature = temperature;
            logEntries[i].humidity = humidity;
            logEntries[i].light = light;
        }
        fprintf(file, "%d,%s,%.2f,%d,%d,%s\n",
                logEntries[i].entryNo,
                logEntries[i].sensorNo,
                logEntries[i].temperature,
                logEntries[i].humidity,
                logEntries[i].light,
                logEntries[i].time);
    }

    fclose(file);
    printf("Entry updated successfully.\n");
}

int main() {
    FILE *file;
    LogEntry logEntries[MAX_ENTRIES];
    int entryCount, entryNo, humidity, light;
    float temperature;

    file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Read the entries from the file and store them in the array
    entryCount = 0;
    while (fscanf(file, "%d,%[^,],%f,%d,%d,%[^,]",
                  &logEntries[entryCount].entryNo,
                  logEntries[entryCount].sensorNo,
                  &logEntries[entryCount].temperature,
                  &logEntries[entryCount].humidity,
                  &logEntries[entryCount].light,
                  logEntries[entryCount].time) == 6) {
        entryCount++;
    }

    fclose(file);

    printf("Enter the EntryNo to update: ");
    scanf("%d", &entryNo);

    printf("Enter the new Temperature: ");
    scanf("%f", &temperature);

    printf("Enter the new Humidity: ");
    scanf("%d", &humidity);

    printf("Enter the new Light: ");
    scanf("%d", &light);

    updateEntry(logEntries, entryCount, entryNo, temperature, humidity, light);

    return 0;
}
