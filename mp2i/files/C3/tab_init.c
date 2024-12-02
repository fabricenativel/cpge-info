#include <stdio.h>
#include <stdlib.h>
int* get_tab(int size, int val)
{
    // Allouer sur le tas la place pour size entiers
    int* tab = malloc(sizeof(int)*size);
    for (int i=0;i<size;i++) 
    {
        tab[i] = val;
    }
    return tab;
}

int main()
{
    int *my_tab = get_tab(10,5);
    for (int i=0;i<10;i++) 
    {
    printf("Valeur en %d = %d\n",i,my_tab[i]);
    }
}
