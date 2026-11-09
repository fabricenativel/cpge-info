#include <stdio.h>
#include <assert.h>

int indice(int tab[], int taille, int elt)
{
    /* Renvoie l'indice de la première occurrence de elt dans tab
     ou -1 si elt n'est pas dans tab  */
    for (int i = 0; i < taille; i++)
    {
        if (tab[i] == elt)
        {
            return i;
        }
        else
        {
            return -1;
        }
    }
}

int main()
{
    int test[4]={2, 5, 6, 1};
    assert (indice(test,3,2)==0);
    assert (indice(test,3,12)==-1);
}