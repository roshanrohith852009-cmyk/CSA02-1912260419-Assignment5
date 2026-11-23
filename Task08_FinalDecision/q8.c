#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char group[4];
} Donor;

typedef struct {
    Donor *data;
    int size;
    int capacity;
} DonorList;

int add_donor(DonorList *list, int id, const char *group) {
    if (list->size == list->capacity) {
        int new_capacity =
            list->capacity == 0 ? 2 : list->capacity * 2;

        Donor *p = realloc(list->data,
                           (size_t)new_capacity * sizeof(Donor));
        if (p == NULL)
            return 0;

        list->data = p;
        list->capacity = new_capacity;
    }

    list->data[list->size].id = id;
    strncpy(list->data[list->size].group, group, 3);
    list->data[list->size].group[3] = '\0';
    list->size++;
    return 1;
}

int main(void) {
    DonorList list = {NULL, 0, 0};
    const char *groups[] = {"O+", "A+", "B-", "AB+", "O-"};

    clock_t start = clock();

    for (int i = 0; i < 100000; i++) {
        if (!add_donor(&list, 7001 + i, groups[i % 5])) {
            fprintf(stderr, "Allocation failed\n");
            free(list.data);
            return 1;
        }
    }

    double elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;

    printf("Donors loaded: %d\n", list.size);
    printf("Capacity: %d\n", list.capacity);
    printf("Allocated memory: %zu bytes\n",
           (size_t)list.capacity * sizeof(Donor));
    printf("Loading time: %.6f seconds\n", elapsed);

    int eligible = 0;
    for (int i = 0; i < list.size; i++)
        if (strcmp(list.data[i].group, "O+") == 0)
            eligible++;

    printf("O+ donors in sample: %d\n", eligible);

    free(list.data);
    list.data = NULL;
    printf("Memory released successfully.\n");

    return 0;
}
