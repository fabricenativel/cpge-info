#include <stdio.h>
#include <assert.h>

struct couple_s
{
    int premier;
    int second;
};
typedef struct couple_s couple;

int min_eleve1(int tab[], int taille)
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

int min_eleve2(int tab[], int taille)
{
    // Renvoie le minimum des éléments de tab (supposé non vide)
    assert(taille > 0);
    int cmin = tab[0];
    for (int i = 0; i < taille - 1; i++)
    {
        if (tab[i + 1] < tab[i])
        {
            cmin = tab[i + 1];
        }
    }
    return cmin;
}

int min(int tab[], int taille)
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

int min_occ(int tab[], int taille, int *nb)
{
    // Renvoie le minimum et affecte à *nb son nombre d'occurrences
    assert(taille > 0);
    int cmin = tab[0];
    *nb = 1;
    for (int i = 1; i < taille; i++)
    {
        if (tab[i] < cmin)
        {
            cmin = tab[i];
            *nb = 1;
        }
        else if (tab[i] == cmin)
        {
            *nb = *nb + 1;
        }
    }
    return cmin;
}

couple deuxmin_couple(int tab[], int taille)
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

void deuxmin(int tab[], int taille, int *min1, int *min2)
{
    // Affecte à *min1 et *min2 les deux plus petites valeurs de tab
    assert(taille > 1);
    if (tab[0] < tab[1]) {
        *min1 = tab[0];
        *min2 = tab[1];
    } else {
        *min1 = tab[1];
        *min2 = tab[0];
    }
    for (int i = 2; i < taille; i++) {
        if (tab[i] < *min1) {
            *min2 = *min1;
            *min1 = tab[i];
        } else if (tab[i] < *min2) {
            *min2 = tab[i];
        }
    }
}

int main()
{
    assert(min_eleve1((int[]){5, -2, 1}, 3) == -2);
    assert(min_eleve1((int[]){5, 7, 2}, 3) == 0);
    assert(min_eleve2((int[]){5, -2, -3}, 3) == -3);
    assert(min_eleve2((int[]){-4, -2, -3}, 3) == -3);

    assert(min((int[]){5, -2, 1}, 3) == -2);
    assert(min((int[]){5, 7, 2}, 3) == 2);

    int nb;
    assert(min_occ((int[]){1, 0, 7, 2}, 4, &nb) == 0 && nb == 1);
    assert(min_occ((int[]){1, 7, -3, 2, -3, 4}, 6, &nb) == -3 && nb == 2);

    int test[10] = {2, 5, 9, 3, 10, 50, -5, 6, 42, 1};
    couple mt = deuxmin_couple(test, 10);
    assert(mt.premier == -5 && mt.second == 1);

    int m1, m2;
    deuxmin(test, 10, &m1, &m2);
    assert(m1 == -5 && m2 == 1);

    printf("Tous les tests passent avec succès !\n");
    return 0;
}