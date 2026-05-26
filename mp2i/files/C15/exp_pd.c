#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int *nbmult_pd(int n)
{
    // Renvoie le nombre de multiplications pour calculer a^n avec un stratégie programmation dynamique
    int *nb = malloc(sizeof(int) * (n + 1));
    nb[0] = 0;
    nb[1] = 0;
    int cmin;
    for (int i = 2; i < n + 1; i++)
    {
        cmin = i - 1;
        for (int k = 1; k < i; k++)
        {
            assert(k < i && i - k < i && k > 0 && i - k > 0);
            if (k == i - k && nb[k] < cmin)
            {
                cmin = nb[k];
            }
            if (k != i - k && nb[k] + nb[i - k] < cmin)
            {
                cmin = nb[k] + nb[i - k];
            }
        }
        nb[i] = 1 + cmin;
    }
    return nb;
}

int* nbmult_rap(int n)
{
    int *nb = malloc(sizeof(int) * (n + 1));
    nb[0] = 0;
    nb[1] = 0;
    for (int i=2;i<n+1;i++)
    {
        if (i%2==0)
        {
            nb[i] = nb[i/2] + 1;
        }
        else
        {
            nb[i] = nb[i/2] + 2;
        }
    }
    return nb;
}

void affiche(int *tab1, int *tab2, int size)
{
    printf("|i\t|pd\t|rap\t|\n");
    printf("-------------------------\n");
    for (int i = 0; i < size; i++)
    {
        printf("|%d\t|%d\t|%d\t|\n", i, tab1[i],tab2[i]);
    }   
}


bool check_eq(int * tab1, int *tab2, int size)
{
    for (int i=0;i<size;i++)
    {
        if (tab1[i]!=tab2[i])
        {
            printf("<> indice %d (%d et %d)\n", i, tab1[i], tab2[i]);
            return false;
        }
    }
    printf("All eq ! \n");
    return true;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Utilisation : %s <entier>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int n = atoi(argv[1]);
    int *res1 = nbmult_pd(n);
    int *res2 = nbmult_rap(n);
    affiche(res1, res2,n+1);
    check_eq(res1, res2, n+1);
    free(res1);
    free(res2);
}