#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

bool est_reflexive(bool * matr, int n)
{
    for (int i = 0; i < n; i++)
        if (!matr[i * n + i])
            return false;
    return true;
}

bool est_antisymetrique(bool * matr, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i!=j && matr[i * n + j] && matr[j * n + i])
                return false;
    return
        true;
}

bool est_transitive(bool * matr, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (matr[i * n + j] && matr[j * n + k] && !matr[i * n + k])
                    return false;
    return true;
}

bool * cree_matrice(int n)
{
    bool * matr = malloc(sizeof(bool) * n * n);
    for (int i=0; i<n; i++)
        {for (int j=0; j<n; j++)
            {matr[i * n + j] = ((j+1)%(i+1) == 0);}}
    return matr;
}

void view(bool * matr, int n)
{
    for (int i=0; i<n; i++)
        {for (int j=0; j<n; j++)
            {if( matr[i * n + j])
            printf("1 ");
            else
            printf("0 ");
            }
        printf("\n");}
}

int main(int argc, char* argv[])
{
    if (argc!=2)
    {
        printf("Usage: %s n\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    bool * matr = cree_matrice(n);
    bool ordre = est_reflexive(matr, n) && est_antisymetrique(matr, n) && est_transitive(matr, n);
    assert (ordre);
    free(matr);
}