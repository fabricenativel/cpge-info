#include <stdio.h>
#include <assert.h>
#include <stdbool.h>



// Echange les éléments situés aux indices i et j dans le tableau tab
void echange(int tab[],int i, int j, int taille)
{   assert(i<taille && j<taille);
    int temp;
    temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

// Renvoie l'indice du minimum des éléments de tab depuis l'indice ind
int min_depuis(int tab[],int taille,int ind)
{   assert (ind<taille && ind>=0);
    int vmin = tab[ind];
    int imin = ind;
    for (int i=ind;i<taille;i++)
    {
        if (tab[i]<vmin )
        {
            imin = i;
            vmin = tab[i];
        }
    }
    return imin;
}

// Tri en place un tableau par sélection
void tri_selection(int tab[], int size){
    for (int i=0;i<size;i++)
    {
        echange(tab,i,min_depuis(tab,size,i),size);
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
    assert ((n%1111!=0) && n>0 && n<10000);
    const int SIZE = 4;
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

// vérifie qu'on atteint bien 6174 et renvoie le nombre d'itérations nécessaires
int verifie(int n)
{
    int nb_iter = 0;
    // Attention si la conjecture est fausse, cette boucle est infinie
    while (n!=6174)
    {
        n = kaprekar(n);
        nb_iter = nb_iter + 1;
    }
    return nb_iter;
}

int main()
{   
    int max_iter = 0;
    int val;
    for (int n=1;n<10000;n++)
    {
        if (n%1111!=0 && verifie(n)>=max_iter)
        {
            max_iter = verifie(n);
            val = n;
        }
    }
    printf("La conjecture est vérifiée ! \n");
    printf("Le nombre d'itérations maximal est %d atteint par %d\n",max_iter,val);
}