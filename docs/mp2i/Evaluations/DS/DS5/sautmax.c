#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>

int valeur(int tab[], int i, int j, int n)
{
    assert(0 <= i && i <= j && j < n);
    return tab[j] - tab[i];
}

int sautmax_naif(int tab[], int n)
{
    // Renvoie le saut maximal en testant tous les sauts possibles
    int smax = 0;
    int sij;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sij = valeur(tab, i, j, n);
            if (sij > smax)
            {
                smax = sij;
            }
        }
    }
    return smax;
}

int max3(int a, int b, int c)
{
    if (a > b && a > c)
    {
        return a;
    }
    if (b > c)
    {
        return b;
    }
    return c;
}

int min(int tab[], int a, int b)
{
    assert(a < b);
    int minv = tab[a];
    for (int i = a + 1; i < b; i++)
    {
        if (tab[i] < minv)
        {
            minv = tab[i];
        }
    }
    return minv;
}

int max(int tab[], int a, int b)
{
    assert(a < b);
    int maxv = tab[a];
    for (int i = a + 1; i < b; i++)
    {
        if (tab[i] > maxv)
        {
            maxv = tab[i];
        }
    }
    return maxv;
}

int sautmax_dpr(int tab[], int a, int b)
{
    // Renvoie le saut maximal du sous tableau t[a],...t[b-1]
    // en utilisant une stratégie diviser pour régner
    if (b - a < 2)
    {
        return 0;
    }
    int p = (b - a) / 2;
    int smg = sautmax_dpr(tab, a, a + p);
    int smd = sautmax_dpr(tab, a + p, b);
    int ming = min(tab, a, a + p);
    int maxd = max(tab, a + p, b);
    int smax = max3(smg, smd, maxd - ming);
    return smax;
}

int sautmax_dyn(int tab[], int n)
{
    int i, j, m;
    i = 0;
    j = 0;
    m = 0;
    for (int k = 1; k < n; k++)
    {
        // Mettre à jour l'indice du minimum
        if (tab[k] < tab[m])
        {
            m = k;
        }
        // Mettre à jour la valeur maximale du saut
        if (tab[k] - tab[m] >= valeur(tab, i, j, n))
        {
            i = m;
            j = k;
        }
    }
    return valeur(tab, i, j, n);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Donner la taille du tableau en ligne de commande !\n");
        return 1;
    }
    int n = atoi(argv[1]);
    double deb, fin;
    srand(time(NULL));
    int *tab = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        tab[i] = rand() % (2 * n);
    }
    deb = (double)clock() / CLOCKS_PER_SEC;
    int smnaif = sautmax_naif(tab, n);
    fin = (double)clock() / CLOCKS_PER_SEC;
    printf("Saut maximal (naif) : %d en %lf\n", smnaif, (fin - deb));
    deb = (double)clock() / CLOCKS_PER_SEC;
    int smdpr = sautmax_dpr(tab, 0, n);
    fin = (double)clock() / CLOCKS_PER_SEC;
    printf("Saut maximal (dpr) : %d en %lf \n", smdpr, (fin - deb));
    deb = (double)clock() / CLOCKS_PER_SEC;
    int smdyn = sautmax_dyn(tab, n);
    fin = (double)clock() / CLOCKS_PER_SEC;
    printf("Saut maximal (dpr) : %d en %lf \n", smdyn, (fin - deb));
}