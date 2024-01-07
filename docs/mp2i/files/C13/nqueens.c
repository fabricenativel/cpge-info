#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 15

int nb_sol = 0;

void affiche(int tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", tab[i]);
    }
    printf("\n");
}

void nqueens(int tab[], int index)
{
    bool ok;
    if (index == SIZE)
    {
        nb_sol++;
        // printf("%d) ->",nb_sol);
        // affiche(tab, SIZE);
    }
    else
    {
        for (int p = 0; p < SIZE; p++)
        {
            ok = true;
            for (int i = 0; i < index; i++)
            {
                if (tab[i] == p || abs(tab[i] - p) == abs(i - index))
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                tab[index] = p;
                nqueens(tab, index + 1);
            }
        }
    }
}

int main()
{
    int tab[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        tab[i] = 0;
    }
    nqueens(tab, 0);
    printf("Problème des %d reines : %d solutions\n", SIZE, nb_sol);
}
