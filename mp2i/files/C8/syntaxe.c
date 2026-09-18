#include <stdio.h>

int main(){
    int tab[] = {2, 3, 5, 7, 11, 13, 17, 19};
    // Avec sucre syntaxique
    int elt5 = tab[5];
    // En utilisant la représentation en mémoire
    int elt5 = *(tab + 5) ;}