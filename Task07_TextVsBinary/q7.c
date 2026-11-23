#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char name[32];
    char group[4];
    int age;
} Donor;

int main(void) {
    const int sizes[] = {10, 1000, 10000, 100000};
    Donor d = {1001, "SampleDonor", "O+", 25};

    for (int k = 0; k < 4; k++) {
        int n = sizes[k];
        clock_t start = clock();

        FILE *text = fopen("donors_test.txt", "w");
        if (!text) {
            perror("text file");
            return 1;
        }

        for (int i = 0; i < n; i++)
            fprintf(text, "%d,%s,%s,%d\n",
                    d.id + i, d.name, d.group, d.age);

        fclose(text);
        double text_write = (double)(clock() - start) / CLOCKS_PER_SEC;

        start = clock();
        FILE *binary = fopen("donors_test.dat", "wb");
        if (!binary) {
            perror("binary file");
            return 1;
        }

        for (int i = 0; i < n; i++) {
            d.id = 1001 + i;
            fwrite(&d, sizeof d, 1, binary);
        }

        fclose(binary);
        double binary_write = (double)(clock() - start) / CLOCKS_PER_SEC;

        printf("Records: %d\n", n);
        printf("Text write time: %.6f seconds\n", text_write);
        printf("Binary write time: %.6f seconds\n\n", binary_write);
    }

    remove("donors_test.txt");
    remove("donors_test.dat");
    return 0;
}
