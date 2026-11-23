#include <stdio.h>
#include <stdbool.h>

void echange(int tableau[], int i, int j) 
    {
    int temp = tableau[i];
    tableau[i] = tableau[j];
    tableau[j] = temp;
    }

int main()
{
    int tab[20];
    tab[0] = 2;
    tab[1] = 7;
    tab[2] = 11;
    tab[3] = 14;
    tab[4] = 9;
    echange(tab,1,3);
    for (int i=0;i<5;i++)
    {
        printf("%d ",tab[i]);
    }
    return 0;
}