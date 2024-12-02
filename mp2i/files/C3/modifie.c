#include <stdio.h>

int main()
{
    int n = 42;
    int *p = &n;
    *p = 2024; // On modifie n (via le contenu de son adresse)
    printf("Valeur de n = %d\n",n); // affiche 2024 
}