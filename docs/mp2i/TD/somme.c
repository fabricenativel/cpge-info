#include <stdio.h>

// Renvoie la somme des éléments d'un tableau
int somme(int tab[], int taille) {
    int s = 0;
    for (int i = 0; i < taille; i++) {
        s += tab[i];
    }
    return s;
}

int main(void) {
    int t[5] = {1, 2, 3, 4, 5};
    printf("Somme = %d\n", somme(t, 5));
    return 0;
}
