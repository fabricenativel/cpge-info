#include <stdio.h>
#include <stdlib.h>

void taille(int tab[])
{
    printf("Taille de  tab dans la fonction : %ld\n",sizeof(tab));
}
int main()
{
    int tab[5] = {1, 2, 6, 3, 7};
    printf("Taille de  tab dans le main  : %ld\n",sizeof(tab));
    taille(tab);
}