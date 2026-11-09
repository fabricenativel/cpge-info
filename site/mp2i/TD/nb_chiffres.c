#include <stdio.h>

// Version itérative en C
int nb_chiffres(int n) {
    if (n == 0) {
        return 1;
    }
    int count = 0;
    while (n > 0) {
        count++;
        n = n / 10;
    }
    return count;
}

int main(void) {
    printf("nb_chiffres(0) = %d\n", nb_chiffres(0));
    printf("nb_chiffres(42) = %d\n", nb_chiffres(42));
    printf("nb_chiffres(2025) = %d\n", nb_chiffres(2025));
    return 0;
}
