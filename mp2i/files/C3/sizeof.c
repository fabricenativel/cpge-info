#include <stdio.h>

int taille(int tab[])
{
    return sizeof(tab)/sizeof(int);
}

int main()
{
    int test[42];
    printf("Taille = %lu \n",sizeof(test)/sizeof(int));
    printf("Taille (fonction) = %d\n",taille(test));
}
