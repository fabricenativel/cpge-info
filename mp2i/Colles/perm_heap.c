#include <stdio.h>
#include <stdlib.h>


void echange(int tab[], int i,int j)
{
    int temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

void affiche(int tab[], int size)
{
    printf("[");
    for (int i=0;i<size;i++)
    {
        printf("%d; ",tab[i]);
    }
    printf("] \n");
}

void gen_permutation(int k, int tab[], int size)
{
    if (k==1) {affiche(tab,size);}
    else
    {
        gen_permutation(k-1, tab, size);
        for (int i=0; i<k-1; i++) {
            if (k%2==0) {
                echange(tab, i, k-1);
            }
            else
                echange(tab, 0, k-1);
        gen_permutation(k-1, tab, size);
        }
    }
}

int main()
{
    int s = 4;
    int t[4] = {1,2,3,4,};
    gen_permutation(4,t,4);
}