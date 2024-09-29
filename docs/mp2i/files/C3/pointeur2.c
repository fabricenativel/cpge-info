#include <stdio.h>
#include <stdlib.h>
int main()
    {
        int *p = malloc(sizeof(int));
        *p = 7;
        printf("Valeur pointée par p = %d",*p);
        printf("Adresse  %p \n",p);

    }
