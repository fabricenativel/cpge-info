# include <stdio.h>

/* Renvoie le nombre d'occurrence de elt dans tab */
int nb_occurence(int elt, int tab[], int size)
{
    int nb = 0;
    for (int i=0; i<size; i++)
    {
        if (tab[i]==elt)
        {
            nb = nb + 1;
        }
    }
    return nb;
}

int main()
{
    int tab[7] = {4, 7, 5, 3, 4, 1, 4};
    printf("Occurences  = %d\n",nb_occurence(10,tab,7));
}