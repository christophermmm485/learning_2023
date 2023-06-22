#include <stdio.h>
#include <string.h>

#define MAX_SENSORS 10

struct SensorInfo {
    char sensorID[10];
    float temperature;
    int humidity;
    int lightIntensity;
};

void parseData(const char* data, struct SensorInfo* sensors, int* numSensors) {
    char sensorID[10];
    float temperature;
    int humidity;
    int lightIntensity;

    // Tokenize the data using '-' and ':'
    char* token = strtok(data, "-");
    int sensorIndex = 0;

    while (token != NULL) {
        sscanf(token, "%[^:]:%f-%[^:]:%d-%[^:]:%d",
               sensorID, &temperature, sensorID, &humidity, sensorID, &lightIntensity);

        // Copy the parsed data into the structure
        strcpy(sensors[sensorIndex].sensorID, sensorID);
        sensors[sensorIndex].temperature = temperature;
        sensors[sensorIndex].humidity = humidity;
        sensors[sensorIndex].lightIntensity = lightIntensity;

        sensorIndex++;

        token = strtok(NULL, "-");
    }

    *numSensors = sensorIndex;
}

void printSensorInfo(const struct SensorInfo* sensors, int numSensors) {
    printf("Sensor Info:\n");
    printf("---------------------\n");

    for (int i = 0; i < numSensors; i++) {
        printf("Sensor ID: %s\n", sensors[i].sensorID);
        printf("Temperature: %.1f C\n", sensors[i].temperature);
        printf("Humidity: %d\n", sensors[i].humidity);
        printf("Light Intensity: %d%%\n", sensors[i].lightIntensity);
        printf("---------------------\n");
    }
}

int main() {
    const char* data = "S1-T:36.5-H:100-L:50";
    struct SensorInfo sensors[MAX_SENSORS];
    int numSensors = 0;

    parseData(data, sensors, &numSensors);
    printSensorInfo(sensors, numSensors);

    return 0;
}
