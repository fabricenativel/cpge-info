#include <stdlib.h>

// Fonction renvoyant un tableau d'entiers de 
// taille size initialisé avec la valeur init
int * make_tab(int size, int init) {
    int * tab = malloc(sizeof(int)*size);
    for (int i=0;i<size;i++)
    { tab[i] = init;}
    return tab;}

int main()
{
    int* test_tab = make_tab(100,42);
    test_tab[0] = 34;
    free(test_tab);
}