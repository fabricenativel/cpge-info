#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool valide(int tab[], int n, int i)
{
    int s = 0;
    for (int k = 0; k < i; k++)
    {
        s += tab[k];
    }
    if (s > n)
    {
        return false;
    }
    int occ[i]; 
    for (int k = 0; k < i; k++)
    {
        occ[k] = 0;
    }
    for (int k = 0; k < i; k++)
    {
        occ[tab[k]]++;
    }
    for (int k = 0; k < i; k++)
    {
        if (occ[k] > tab[k])
        {
            return false;
        }
    }
    return true;
}

bool est_autoreferent(int tab[], int n)
{
    // On initialise les occurrences de toutes les valeurs à 0
    int occ[n];
    for (int k = 0; k < n; k++)
    {
        occ[k] = 0;
    } 
    // On parcourt en incrémentant les occurrences
    for (int i = 0; i < n; i++)
    {
        occ[tab[i]]++;
    }
    // On teste si le tableau est autoréférent
    for (int i = 0; i < n; i++)
    {
        if (occ[i] != tab[i])
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