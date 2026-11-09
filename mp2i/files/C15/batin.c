#include <stdio.h>

double moyenne(int tableau[], int taille) {
    if (taille == 0) return 0.0;
    int somme = 0;
    for (int i = 0; i < taille; i++) {
        somme += tableau[i];
    }
    return (double)somme / taille;
}


int main() {
    int tableau[] = {10, 20, 30, 40, 50};
    int taille = sizeof(tableau) / sizeof(tableau[0]);#include <stdio.h>

    // Non, en C il n'est pas possible de calculer la taille d'un tableau passé en paramètre à une fonction,
    // car il est converti en pointeur. Il faut donc toujours passer la taille séparément.
    double moy = moyenne(tableau, taille);
    printf("La moyenne est : %.2f\n", moy);
    return 0;
}