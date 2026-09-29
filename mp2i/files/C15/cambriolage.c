#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool incremente(bool compteur[], int n)
{
    int idx = n - 1;
    while (idx >= 0 && compteur[idx])
    {
        compteur[idx--] = false;
    }
    if (idx == -1)
    {
        for (int i = 0; i < n; i++)
        {
            compteur[i] = true;
        }
        return false;
    }
    compteur[idx] = 1;
    return true;
}

bool est_valide(bool choix[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (choix[i] && choix[i + 1])
        {
            return false;
        }
    }
    return true;
}

int forcebrute(int butin[], int n)
{
    bool *choix = malloc(sizeof(bool) * n);
    for (int i = 0; i < n; i++)
    {
        choix[i] = false;
    }
    int smax = 0;
    int sc = 0;
    while (incremente(choix, n))
    {
        if (est_valide(choix, n))
        {
            sc = 0;
            for (int j = 0; j < n; j++)
            {
                if (choix[j])
                {
                    sc += butin[j];
                }
            }
        }
        if (sc > smax)
        {
            smax = sc;
        }
    }
    free(choix);
    return smax;
}

int glouton(int butin[], int n)
{
    // On ne considère que les deux choix suivants possibles et on prend le plus grand des deux
    int sc = 0;
    int i = 0;
    while (i < n - 1)
    {
        if (i == n - 1 || butin[i] > butin[i + 1])
        {
            sc += butin[i];
            i += 2;
        }
        else
        {
            sc += butin[i + 1];
            i = i + 3;
        }
    }
    return sc;
}

int prog_dyn(int butin[], int n, int i)
{
    if (i > n - 1)
    {
        return 0;
    }
    if (i == n - 1)
    {
        return butin[n - 1];
    }
    int sans_i = prog_dyn(butin, n, i + 1);
    int avec_i = butin[i] + prog_dyn(butin, n, i + 2);
    if (sans_i > avec_i)
    {
        return sans_i;
    }
    else
    {
        return avec_i;
    }
}

int prog_dyn_bu(int butin[], int n)
{
    int *s = malloc(sizeof(int) * (n + 1));
    s[n] = 0;
    s[n - 1] = butin[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (butin[i] + s[i + 2] > s[i + 1])
        {
            s[i] = butin[i] + s[i + 2];
        }
        else
        {
            s[i] = s[i + 1];
        }
    }
    int mv = s[0];
    for (int i = 0; i <= n; i++)
    {
        printf("%d, ", s[i]);
    }
    printf("\n");
    int c = 0;
    while (c < n)
    {
        if (butin[c] + s[c + 2] == s[c])
        {
            printf("%d, ", c);
            c = c + 2;
        }
        else
        {
            c = c + 1;
        }
    }
    printf("\n");
    free(s);
    return mv;
}

int *random_tab(int seed, int size, int minvalue, int maxvalue)
{
    srand(seed);
    int *tab = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        tab[i] = minvalue + rand() % (maxvalue - minvalue + 1);
    }
    return tab;
}

int main()
{
    int nb = 20;
    int *butins = malloc(sizeof(int) * nb);
    srand(time(NULL));
    for (int i = 0; i < nb; i++)
    {
        butins[i] = 1 + rand() % 100;
        printf("%d, ", butins[i]);
    }
    printf("\n");
    int fb = forcebrute(butins, nb);
    int gl = glouton(butins, nb);
    int pd = prog_dyn(butins, nb, 0);
    int pd_bu = prog_dyn_bu(butins, nb);
    printf("Force brute : %d\n", fb);
    printf("Glouton : %d\n", gl);
    printf("Programmation dynamique : %d\n", pd);
    printf("Programmation dynamique (bottom up): %d\n", pd_bu);
    //int seed = 42;
    //int size = 1000;
    //int *test = random_tab(seed, size, 1, 5000);
    //pd_bu = prog_dyn_bu(test, size);
    //printf("Programmation dynamique (bottom up): %d\n", pd_bu);
    //free(test);
}