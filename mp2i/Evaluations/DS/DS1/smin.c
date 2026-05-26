#include <stdio.h>
#include <assert.h>

struct couple_s
{
    int premier;
    int second;
};
typedef struct couple_s couple;

int min_eleve(int tab[], int taille)
{
    // Renvoie le minimum des éléments de tab (supposé non vide)
    assert(taille > 0);
    int cmin = 0;
    for (int i = 0; i < taille; i++)
    {
        if (tab[i] < cmin)
        {
            cmin = tab[i];
        }
    }
    return cmin;
}

int min_corrige(int tab[], int taille)
{
    // Renvoie le minimum des éléments de tab (supposé non vide)
    assert(taille > 0);
    int cmin = tab[0];
    for (int i = 1; i < taille; i++)
    {
        if (tab[i] < cmin)
        {
            cmin = tab[i];
        }
    }
    return cmin;
}

couple deuxmin(int tab[], int taille)
{
    assert(taille > 1);
    couple min;
    if (tab[0] < tab[1])
    {
        min.premier = tab[0];
        min.second = tab[1];
    }
    else
    {
        min.premier = tab[1];
        min.second = tab[0];
    }
    for (int i = 2; i < taille; i++)
    {
        if (tab[i] < min.premier)
        {
            min.second = min.premier;
            min.premier = tab[i];
        }
        else if (tab[i] < min.second)
        {
            min.second = tab[i];
        }
    }
    return min;
}


void deuxmin2(int tab[], int taille, int* min1, int* min2)
{
    assert(taille > 1);
    if (tab[0] < tab[1])
    {
        *min1 = tab[0];
        *min2 = tab[1];
    }
    else
    {
        *min1 = tab[1];
        *min2 = tab[0];
    }
    for (int i = 2; i < taille; i++)
    {
        if (tab[i] < *min1)
        {
            *min2 = *min1;
            *min1 = tab[i];
        }
        else if (tab[i] < *min2)
        {
            *min2 = tab[i];
        }
    }
}

int main()
{
    int test[10] = {2, 5, 9, 3, 10, 50, -5, 6, 42, 1};
    couple mt = deuxmin(test, 10);
    int m1, m2;
    deuxmin2(test,10,&m1,&m2);
    printf("Les deux minimus sont %d et %d \n", mt.premier, mt.second);
    printf("Les deux minimus sont %d et %d \n", m1, m2);
}