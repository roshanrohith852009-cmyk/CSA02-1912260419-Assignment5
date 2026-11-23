#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[40];
    char group[4];
    int age;
} Donor;

typedef struct {
    int group_code;
    int units;
} Stock;

int save_donors_text(const char *filename,
                     const Donor donors[], int n) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("fopen donor file");
        return 0;
    }

    for (int i = 0; i < n; i++)
        fprintf(fp, "%d,%s,%s,%d\n",
                donors[i].id, donors[i].name,
                donors[i].group, donors[i].age);

    fclose(fp);
    return 1;
}

int save_stock_binary(const char *filename,
                      const Stock stock[], int n) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen stock file");
        return 0;
    }

    int ok = fwrite(stock, sizeof(Stock), (size_t)n, fp) == (size_t)n;
    fclose(fp);
    return ok;
}

int update_units(FILE *fp, int index, int units) {
    Stock s;

    if (fp == NULL || index < 0 || units < 0)
        return 0;

    if (fseek(fp, (long)index * (long)sizeof(Stock), SEEK_SET) != 0)
        return 0;

    if (fread(&s, sizeof(Stock), 1, fp) != 1)
        return 0;

    s.units = units;

    if (fseek(fp, -(long)sizeof(Stock), SEEK_CUR) != 0)
        return 0;

    if (fwrite(&s, sizeof(Stock), 1, fp) != 1)
        return 0;

    return fflush(fp) == 0;
}

int main(void) {
    Donor donors[] = {
        {101, "Arun", "O+", 25},
        {102, "Kumar", "A+", 32},
        {103, "Ravi", "B-", 29}
    };

    Stock stock[] = {
        {1, 40}, {2, 25}, {3, 12}, {4, 8}, {5, 30}
    };

    if (!save_donors_text("donors.txt", donors, 3))
        return 1;

    if (!save_stock_binary("stock.dat", stock, 5))
        return 1;

    FILE *fp = fopen("stock.dat", "r+b");
    if (fp == NULL) {
        perror("stock.dat");
        return 1;
    }

    printf("update record 3: %s\n",
           update_units(fp, 3, 20) ? "done" : "failed");
    printf("update record 9: %s\n",
           update_units(fp, 9, 20) ? "done" : "failed");

    fclose(fp);
    printf("Donor text and stock binary files saved.\n");
    return 0;
}
