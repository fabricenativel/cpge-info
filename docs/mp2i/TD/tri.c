#include <stdbool.h>
#include <stdio.h>

// Vérifie qu'un tableau est trié dans l'ordre croissant
bool est_trie(int tab[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (tab[i] > tab[i + 1]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    int t1[5] = {1, 3, 5, 7, 9};
    int t2[5] = {1, 5, 3, 7, 9};
    printf("t1 trié : %d\n", est_trie(t1, 5));
    printf("t2 trié : %d\n", est_trie(t2, 5));
    return 0;
}
