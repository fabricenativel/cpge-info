#include <stdio.h>
#include <stdlib.h>
int n_global;

int main()
{
    int n_local;
    int *n_tas = malloc(sizeof(int));
    printf("Adresse de l'entier en variable globale : %p\n",&n_global);
    printf("Adresse de l'entier en variable locale : %p\n",&n_local);
    printf("Adresse de l'entier dans le tas : %p\n",n_tas);
}