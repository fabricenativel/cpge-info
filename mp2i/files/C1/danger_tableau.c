#include <stdio.h>

int main()
{
    int tab[10];
    int x = tab[10] + 42; //UB !
    printf("Valeur de x = %d\n", x);
    int tab1[4] = {17, 11, 9, 4};
    int tab2 = tab1; // Produit un Warning !
    int t[5] = {4, 2, 6, 1, 8};
    int s = somme(t); // Impossible de déterminer la taille de t dans la fonction somme
}