#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int dichotomie(int tab[], int valeur, int debut, int fin)
{
    if (debut > fin)
    {
        return -1;
    }
    int milieu = (debut + fin) / 2;
    if (tab[milieu] == valeur)
    {
        return milieu;
    }
    if (tab[milieu] < valeur)
    {
        return dichotomie(tab, valeur, milieu + 1, fin);
    }
    return dichotomie(tab, valeur, debut, milieu - 1);
}

int dichotomie_iter(int tab[], int valeur, int size)
{
    int debut = 0;
    int fin = size-1;
    int milieu;
    bool trouve = false;
    while (fin>=debut && !trouve)
    {
        milieu = (debut+fin)/2;
        if (tab[milieu]==valeur)
        {
            trouve = true;
        }
        else if (tab[milieu]<valeur)
        {
            debut = milieu+1;
        }
        else
        {
            fin = milieu-1;
        }
    }
    if (trouve)
    {
        return milieu;
    }
    return -1;
}

int main()
{
    int tab[] = {14, 15, 17, 22, 23, 25, 29, 34, 38};
    assert(dichotomie(tab, 28, 0, 8) == -1);
    assert(dichotomie(tab, 14, 0, 8) == 0);
    assert(dichotomie(tab, 38, 0, 8) == 8);
    assert(dichotomie(tab, 17, 0, 8) == 2);
    assert(dichotomie_iter(tab, 28, 9) == -1);
    assert(dichotomie_iter(tab, 14, 9) == 0);
    assert(dichotomie_iter(tab, 38, 9) == 8);
    assert(dichotomie_iter(tab, 17, 9) == 2);
}