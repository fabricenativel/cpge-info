#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>

double valeur(double tab[], int i, int j, int n)
{
    assert(0 <= i && i <= j && j < n);
    return tab[j] - tab[i];
}

double sautmax_naif(double tab[], int n)
{
    // Renvoie le saut maximal en testant tous les sauts possibles
    double smax = 0;
    double sij;
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

void indices_sautmax(double tab[], int n, int *im, int *jm)
{
    double smax = 0;
    double sij = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sij = valeur(tab, i, j, n);
            if (sij > smax)
            {
                *im =i;
                *jm =j;
                smax = sij;
            }
        }
    }
}

double max3(double a, double b, double c)
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

double min(double tab[], int a, int b)
{
    assert(a < b);
    double minv = tab[a];
    for (int i = a + 1; i < b; i++)
    {
        if (tab[i] < minv)
        {
            minv = tab[i];
        }
    }
    return minv;
}

double max(double tab[], int a, int b)
{
    assert(a < b);
    double maxv = tab[a];
    for (int i = a + 1; i < b; i++)
    {
        if (tab[i] > maxv)
        {
            maxv = tab[i];
        }
    }
    return maxv;
}

double sautmax_dpr(double tab[], int a, int b)
{
    // Renvoie le saut maximal du sous tableau t[a],...t[b-1]
    // en utilisant une stratégie diviser pour régner
    if (b - a < 2)
    {
        return 0;
    }
    int p = (b - a) / 2;
    double smg = sautmax_dpr(tab, a, a + p);
    double smd = sautmax_dpr(tab, a + p, b);
    double ming = min(tab, a, a + p);
    double maxd = max(tab, a + p, b);
    double smax = max3(smg, smd, maxd - ming);
    return smax;
}

double sautmax_dyn(double tab[], int n)
{
    int i, j, m;
    i = 0;
    j = 0;
    m = 0;
    for (int k = 1; k < n; k++)
    {
        // Mettre à jour la valeur maximale du saut
        if (tab[k] - tab[m] >= valeur(tab, i, j, n))
        {
            i = m;
            j = k;
        }
        // Mettre à jour l'indice du minimum
        if (tab[k] < tab[m])
        {
            m = k;
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
    double *tab = malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++)
    {
        tab[i] =  rand() % (n * n);
    }
    deb = (double)clock() / CLOCKS_PER_SEC;
    double smnaif = sautmax_naif(tab, n);
    fin = (double)clock() / CLOCKS_PER_SEC;
    printf("Saut maximal (naif) : %lf en %lf\n", smnaif, (fin - deb));
    deb = (double)clock() / CLOCKS_PER_SEC;
    double smdpr = sautmax_dpr(tab, 0, n);
    fin = (double)clock() / CLOCKS_PER_SEC;
    printf("Saut maximal (dpr) : %lf en %lf \n", smdpr, (fin - deb));
    deb = (double)clock() / CLOCKS_PER_SEC;
    double smdyn = sautmax_dyn(tab, n);
    fin = (double)clock() / CLOCKS_PER_SEC;
    printf("Saut maximal (dpr) : %lf en %lf \n", smdyn, (fin - deb));
    int im;
    int jm;
    indices_sautmax(tab, n, &im, &jm);
    printf("Indices du saut maximal : %d %d - Check : %lf\n", im, jm, valeur(tab, im, jm, n));
    free(tab);
}