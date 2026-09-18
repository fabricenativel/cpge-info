#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



bool menace(int tab[], int idx)
{
    // renvoie vrai si la reine située à la colonne idx menace une des reines situées avant (entre 0 et idx-1)
    // 
    for (int i = 0; i <= idx - 1; i++)
    {
        if (tab[i] == tab[idx] || abs(tab[i] - tab[idx]) == idx - i)
        {
            return true;
        }
    }
    return false;
}