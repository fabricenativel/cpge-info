#include <stdio.h>

void affiche(int tab[], int n)
{
    if (n == 0)
    {
        printf("[ ]\n");
    }
    else
    {
        printf("[");
        for (int i = 0; i < n - 1; i++)
        {
            printf("%d, ", tab[i]);
        }
        printf("%d]\n", tab[n - 1]);
    }
}

void echange(int tab[], int i, int j)
{
    tab[i] = tab[i] + tab[j];
    tab[j] = tab[i] - tab[j];
    tab[i] = tab[i] - tab[j];
}

void rotation_droite(int tab[], int n)
{
    for (int k=0;k<n;k++)
    {
        echange(tab, 0, (k+1)%n);
    }
}

int main()
{
    int test[5] = {1, 2, 3, 4, 5};
    affiche(test,5);
    rotation_droite(test, 5);
    affiche(test,5);
}