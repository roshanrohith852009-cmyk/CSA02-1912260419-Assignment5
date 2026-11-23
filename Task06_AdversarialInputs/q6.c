#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char name[20];

    if (argc > 2) {
        fprintf(stderr, "Usage: program [blood-group]\n");
        return 1;
    }

    if (argc == 2) {
        const char *valid[] = {"A+", "A-", "B+", "B-",
                               "AB+", "AB-", "O+", "O-"};
        int found = 0;

        for (int i = 0; i < 8; i++)
            if (strcmp(argv[1], valid[i]) == 0)
                found = 1;

        if (!found) {
            fprintf(stderr, "Invalid blood group\n");
            return 1;
        }
        printf("Selected group: %s\n", argv[1]);
    } else {
        printf("No group supplied. Showing all groups.\n");
    }

    printf("Enter donor name: ");
    if (fgets(name, sizeof name, stdin) == NULL) {
        fprintf(stderr, "Input error\n");
        return 1;
    }

    name[strcspn(name, "\n")] = '\0';

    if (strlen(name) == sizeof name - 1) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        printf("Name may have been truncated to fit the buffer.\n");
    }

    printf("Donor name: %s\n", name);

    FILE *fp = fopen("missing_data.txt", "r");
    if (fp == NULL)
        perror("Could not open data file");
    else
        fclose(fp);

    return 0;
}
