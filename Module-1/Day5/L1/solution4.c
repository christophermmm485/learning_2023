#include <stdio.h>

// Structure to represent a time period
struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Function to calculate the difference between two time periods
struct Time calculateTimeDifference(struct Time start, struct Time end) {
    struct Time diff;
    int totalSecondsStart, totalSecondsEnd, diffSeconds;

    // Convert start time to seconds
    totalSecondsStart = start.hours * 3600 + start.minutes * 60 + start.seconds;

    // Convert end time to seconds
    totalSecondsEnd = end.hours * 3600 + end.minutes * 60 + end.seconds;

    // Calculate difference in seconds
    diffSeconds = totalSecondsEnd - totalSecondsStart;

    // Convert difference back to hours, minutes, and seconds
    diff.hours = diffSeconds / 3600;
    diffSeconds %= 3600;
    diff.minutes = diffSeconds / 60;
    diff.seconds = diffSeconds % 60;

    return diff;
}

int main() {
    struct Time startTime, endTime, timeDiff;

    printf("Enter the start time (hh:mm:ss): ");
    scanf("%d:%d:%d", &startTime.hours, &startTime.minutes, &startTime.seconds);

    printf("Enter the end time (hh:mm:ss): ");
    scanf("%d:%d:%d", &endTime.hours, &endTime.minutes, &endTime.seconds);

    timeDiff = calculateTimeDifference(startTime, endTime);

    printf("\nDifference between the two time periods:\n");
    printf("Hours: %d, Minutes: %d, Seconds: %d\n", timeDiff.hours, timeDiff.minutes, timeDiff.seconds);

    return 0;
}
