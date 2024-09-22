#include <stdio.h>

// Renvoie un tableau contenant les entiers de 0 à n-1
int *cree_tab_entiers(int n)
{
    int tab_entiers[n];
    for (int i = 0; i < n; i++)
    {
        tab_entiers[i] = i;
    }
    return tab_entiers;
}

int main()
{
}