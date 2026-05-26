#include <stdio.h>

int main()
{
    int n = 42; // Dans la pile (variable locale)
    int *p = &n; // p est un pointeur vers n, stocké dans la pile
    *p = 2024; // On modifie n (via le contenu de son adresse)
    printf("Valeur de n = %d\n",n); // affiche 2024 
}