#include <stdio.h>

void echange(int tab[], int i, int j)
{
 int temp = tab[i];
 tab[i] = tab[j];
 tab[j] = temp;   
}

// insere en supposant la partie avant i déjà triée
void insere(int tab[], int i)
{
    int pos = i;
    while (pos>0 && (tab[pos]<tab[pos-1]))
    {
    echange(tab,pos,pos-1);
    pos = pos - 1;
    }
}

void tri_insertion(int tab[], int taille)
{
    for (int i=0;i<taille;i++)
    {
        insere(tab,i);
    }
}

int main()
{
    int tab[5] = {12, 10, 18, 11, 14};
    tri_insertion(tab,5);
    for (int i=0;i<5;i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");
    return 0;
}