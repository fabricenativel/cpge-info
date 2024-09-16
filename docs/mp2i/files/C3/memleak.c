#include <stdio.h>
#include <stdlib.h>

void memory_leak()
{
    int *tab = malloc(sizeof(int)*100);
    tab[0] = 42;
    printf("On quitte sans libérer tab !\n");
}
int main()
{
    memory_leak();
    printf("Il devient ici impossible de libérer tab\n");
}