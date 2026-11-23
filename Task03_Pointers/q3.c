#include <stdio.h>
#include <string.h>

int *lowest_stock(int stock[], int n) {
    if (n <= 0) return NULL;

    int *lowest = &stock[0];

    for (int i = 1; i < n; i++)
        if (stock[i] < *lowest)
            lowest = &stock[i];

    return lowest;
}

int lowest_index(const int stock[], int n) {
    if (n <= 0) return -1;

    int index = 0;
    for (int i = 1; i < n; i++)
        if (stock[i] < stock[index])
            index = i;

    return index;
}

int main(void) {
    int stock[8] = {40, 25, 12, 8, 30, 19, 50, 15};
    int *p = stock;

    printf("p + 3 address: %p\n", (void *)(p + 3));
    printf("*(p + 3): %d\n", *(p + 3));
    printf("p[3]: %d\n", p[3]);
    printf("*p++: %d\n", *p++);

    int *lowest = lowest_stock(stock, 8);
    if (lowest != NULL) {
        printf("Lowest stock: %d\n", *lowest);
        *lowest += 5;
        printf("Updated stock: %d\n", *lowest);
    }

    printf("Lowest index: %d\n", lowest_index(stock, 8));
    return 0;
}
