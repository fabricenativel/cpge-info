#include <stdio.h>

void init_pointer(int *p, int *adr)
{
    //Initialise le pointeur p à l'adresse de val
    p = adr;
}

int main()
{
    int a = 42;
    int *p = NULL;
    init_pointer(p, &a);
    printf("Valeur pointée par p : %d\n", *p);
}