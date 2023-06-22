#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_FIELD_SIZE 100

struct Entry {
    char EntryNo[MAX_FIELD_SIZE];
    char Field1[MAX_FIELD_SIZE];
    char Field2[MAX_FIELD_SIZE];
    // Add more fields as needed
};

void delete_entry_by_entryno(const char* entryno) {
    struct Entry entries[MAX_ENTRIES];
    int num_entries = 0;

    // Open the input file
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    // Read the entries from the file and store them in the array
    while (num_entries < MAX_ENTRIES && fscanf(file, "%[^,],%[^,],%[^\n]\n",
                                              entries[num_entries].EntryNo,
                                              entries[num_entries].Field1,
                                              entries[num_entries].Field2) == 3) {
        num_entries++;
    }

    // Close the file
    fclose(file);

    // Find the index of the entry to delete
    int delete_index = -1;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].EntryNo, entryno) == 0) {
            delete_index = i;
            break;
        }
    }

    if (delete_index == -1) {
        printf("Entry not found.\n");
        return;
    }

    // Shift the remaining entries to overwrite the entry to delete
    for (int i = delete_index; i < num_entries - 1; i++) {
        memcpy(&entries[i], &entries[i + 1], sizeof(struct Entry));
    }

    // Open the file in write mode to overwrite the existing content
    file = fopen("data.csv", "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    // Write the updated entries back to the file
    for (int i = 0; i < num_entries - 1; i++) {
        fprintf(file, "%s,%s,%s\n", entries[i].EntryNo, entries[i].Field1, entries[i].Field2);
    }

    // Close the file
    fclose(file);

    printf("Entry deleted successfully.\n");
}

int main() {
    const char* entryno_to_delete = "123";
    delete_entry_by_entryno(entryno_to_delete);
    return 0;
}
