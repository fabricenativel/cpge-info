#include <stdio.h>

void echange(int tab[], int i, int j)
{
    tab[i] = tab[i] + tab[j];
    tab[j] = tab[i] - tab[j];
    tab[i] = tab[i] - tab[j];
}

void rotation(int tab[], int n)
{
    for (int i=1; i<n;i++)
    {
        echange(tab, i, 0);
    }
}

void affiche(int tab[], int n)
{
    printf("{");
    for (int i=0;i<n-1;i++)
    {
        printf("%d,",tab[i]);
    }
    printf("%d}\n",tab[n-1]);
}

int main()
{
    int test[5] = {2, 3, 4, 8, 1};
    affiche(test, 5);
    rotation(test, 5);
    affiche(test, 5);
}