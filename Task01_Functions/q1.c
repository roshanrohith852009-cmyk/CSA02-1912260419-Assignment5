#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char group[4];
    int age;
    char phone[16];
    int last_donation_day;
} Donor;

typedef struct {
    int eligible_count;
    int youngest_donor_id;
} EligibilityResult;

int check_eligibility(const Donor *d, int current_day) {
    return current_day - d->last_donation_day >= 90;
}

int find_donors(const Donor donors[], int n, const char *group,
                int current_day, int *youngest_id) {
    int count = 0, youngest_age = 1000;
    *youngest_id = -1;

    for (int i = 0; i < n; i++) {
        if (strcmp(donors[i].group, group) == 0 &&
            check_eligibility(&donors[i], current_day)) {
            count++;
            if (donors[i].age < youngest_age) {
                youngest_age = donors[i].age;
                *youngest_id = donors[i].id;
            }
        }
    }
    return count;
}

EligibilityResult find_result(const Donor donors[], int n,
                              const char *group, int day) {
    EligibilityResult result = {0, -1};
    int youngest_age = 1000;

    for (int i = 0; i < n; i++) {
        if (strcmp(donors[i].group, group) == 0 &&
            check_eligibility(&donors[i], day)) {
            result.eligible_count++;
            if (donors[i].age < youngest_age) {
                youngest_age = donors[i].age;
                result.youngest_donor_id = donors[i].id;
            }
        }
    }
    return result;
}

int main(void) {
    Donor donors[] = {
        {101, "Arun", "O+", 25, "9876543210", 100},
        {102, "Kumar", "O+", 35, "9876543211", 200},
        {103, "Ravi", "A+", 22, "9876543212", 100},
        {104, "Mani", "O+", 19, "9876543213", 50}
    };

    int youngest;
    int count = find_donors(donors, 4, "O+", 250, &youngest);

    printf("Eligible donors: %d\n", count);
    printf("Youngest donor ID: %d\n", youngest);

    EligibilityResult r = find_result(donors, 4, "O+", 250);
    printf("Structure result: %d, ID %d\n",
           r.eligible_count, r.youngest_donor_id);

    return 0;
}
