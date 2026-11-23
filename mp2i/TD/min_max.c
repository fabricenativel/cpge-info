#include <stdio.h>

// Recherche simultanée du minimum et du maximum en ceil(3n/2) - 2 comparaisons
void min_max(int t[], int n, int *pmin, int *pmax) {
    int i;
    if (n % 2 != 0) {
        *pmin = t[0];
        *pmax = t[0];
        i = 1;
    } else {
        if (t[0] < t[1]) {
            *pmin = t[0];
            *pmax = t[1];
        } else {
            *pmin = t[1];
            *pmax = t[0];
        }
        i = 2;
    }
    while (i < n - 1) {
        if (t[i] < t[i + 1]) {
            if (t[i] < *pmin) *pmin = t[i];
            if (t[i + 1] > *pmax) *pmax = t[i + 1];
        } else {
            if (t[i + 1] < *pmin) *pmin = t[i + 1];
            if (t[i] > *pmax) *pmax = t[i];
        }
        i += 2;
    }
}

int main(void) {
    int t[7] = {3, 7, 2, 9, 1, 8, 4};
    int min, max;
    min_max(t, 7, &min, &max);
    printf("min = %d, max = %d\n", min, max);
    return 0;
}
