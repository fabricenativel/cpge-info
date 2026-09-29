#include <stdio.h>
#include <stdlib.h>

int* get_adr_local()
{
    int n_local = 15;
    return &n_local;
}

int main()
{
    int *p = get_adr_local();
    printf("Adresse de la variable locale = %p",p);
    printf("Contenu = %d",*p);
}