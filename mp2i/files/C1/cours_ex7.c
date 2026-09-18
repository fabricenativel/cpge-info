#include <stdio.h>
#include <stdbool.h>

bool croissant(int tableau[], int taille)
{
    for (int i = 0; i < taille - 1; i = i + 1)
    {
        if (tableau[i] > tableau[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int tab[20];
    tab[0] = 2;
    tab[1] = 7;
    tab[2] = 11;
    tab[3] = 14;
    tab[4] = 9;
    if (croissant(tab, 5))
        printf("True");
    else
        printf("False");
}