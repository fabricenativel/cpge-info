#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

# define SIZE 4


int tous_egaux(int n)
{
    int chiffre = n%10;
    int div = 1;
    int poids=10;
    for (int i=1;i<SIZE;i++)
    {
        div = div+poids;
        poids = poids*10;
    }
    return (n/div == chiffre);

}

// Min depuis, renvoie l'indice du minimum des éléments de tab depuis l'indice ind
int min_depuis(int tab[],int size,int ind)
{
    int vmin = tab[ind];
    int imin = ind;
    for (int i=ind;i<size;i++)
    {
        if (tab[i]<vmin )
        {
            imin = i;
            vmin = tab[i];
        }
    }
    return imin;
}

void echange(int tab[],int i, int j)
{
    int temp;
    temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

// Tri en place un tableau par sélection
void tri_selection(int tab[], int size){
    for (int i=0;i<size;i++)
    {
        echange(tab,i,min_depuis(tab,size,i));
    }

}

void retourne(int tab[],int rtab[],int size) {
    for (int i=0;i<size;i++)
    {
        rtab[i] = tab[size-i-1];
    }
}

int valeur(int tab[],int size)
{
    int v = 0;
    int poids = 1;
    for (int i=0;i<size;i++)
    {
        v =v + tab[i]*poids;
        poids = poids * 10;
    }
    return v;
}

int kaprekar(int n){
    assert (!tous_egaux(n));
    int tab[SIZE];
    int rtab[SIZE];
    int n1,n2;
    for (int i=0;i<SIZE;i++)
    {
        tab[i] = n%10;
        n=n/10;
    }
    tri_selection(tab,SIZE);
    retourne(tab,rtab,SIZE);
    n1 = valeur(rtab,SIZE);
    n2 = valeur (tab,SIZE);
    return n2-n1;
}


bool show(int n,bool view)
{
    int iter = 0;
    int kn;
    while ((kn=kaprekar(n))!=n) {
        iter++;
        n=kn;
        if (view)
        {
        printf("K%d=",iter);
        printf("%d\n",kn);}}
    return true;
}

int main()
{   
    for (int i=0;i<10000;i++)
    {
        if (!tous_egaux(i) && show(i,false))
        {
            printf("%d : ok\n",i);
        }
    }
}