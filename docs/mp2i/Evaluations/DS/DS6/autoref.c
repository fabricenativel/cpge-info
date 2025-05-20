#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool valide(int tab[], int n, int i)
{
    // Validation partielle d'un tableau autoréférent jusqu'à l'indice i
    int s = 0;
    for (int k = 0; k < i; k++)
    {
        s += tab[k];
    }
    if (s > n)
    {
        return false;
    }
    return true;
}

bool est_autoreferent(int tab[], int n)
{
    // Validation complète d'un tableau autoréférent
    int c[n];
    for (int i = 0; i < n; i++)
    {
        c[i] =0;
    }
    for (int i = 0; i < n; i++)
    {
        c[tab[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (c[i] != tab[i])
        {
            return false;
        }
    }
    return true;
}

bool autoreferent(int tab[], int n, int i)
{
    if (i == n)
    {
        return est_autoreferent(tab,n);
    }
    for (int k = 0; k <= n; k++)
    {
        tab[i] = k;
        if (valide(tab, n, i))
        {
            if (autoreferent(tab, n, i + 1))
            {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    if (argc!=2)
    {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    int *tab = malloc(n * sizeof(int));
    if (autoreferent(tab, n, 0))
    {
        printf("Le tableau est autoréférent.\n");
        for (int i=0; i < n; i++)
        {
            printf("%d ", tab[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Le tableau n'est pas autoréférent.\n");
    }
    free(tab);
    return 0;
}