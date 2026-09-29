#include <stdio.h>
#include <stdint.h>

// Renvoie la somme des éléments de tab
int somme(int tab[], int size)
{
    int s = 0;
    for (int i=0;i<size;i++)
    {
        s = s + tab[i];
    }
    return s;
}


int somme(int tab[], int size){
    int s = 0;
    for (int i=0;i<size;i++){
        s = s + tab[i];}
    return s;}

int main()
{
    int test[5] = {1, 9, 5, 4, 2};
    printf("Résultat = %d\n",somme(test,5));
}
