#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



bool est_autoreferent(int tab[], int n)
{
    // Vérifie si le tableau est autoréférent
    
}


bool valide(int tab[], int n, int i)
{   // Vérifie que le tableau peut encore être complété pour être autoréférent
    
    return true;
}

bool autoreferent(int tab[], int n, int i)
{
    if (i == n)
    {
        return est_autoreferent(tab,n);
    }
    for (int k = .......)
    {
        tab[i] = k;
        if (valide(tab, n, i))
        {
            if (autoreferent(........))
            {
                return .....;
            }
        }
    }
    return ......;
}

int main(int argc, char *argv[])
{
    
}