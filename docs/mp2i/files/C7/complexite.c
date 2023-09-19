#include <stdio.h>
#include <stdbool.h>

bool est_dans(int elt, int tab[], int size){
    for (int i=0; i<size; i=i+1)
        {if (tab[i]==elt)
            {return true;}}
    return false;}