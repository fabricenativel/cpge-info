#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *t = malloc(sizeof(int)*4);
    t[1] = 17;
    t[3] = 12;
    t[0] = t[1] + t[3];
    int tab[] = {4,5,6,7};
    printf("Test1 = %p\n",&(tab[0]));
    printf("Test1 = %p\n",tab);
}