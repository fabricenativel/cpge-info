#include <stdio.h>
#include <assert.h>

int get_imax(int tab[],int size) {
    /*  Prend en argument un tableau non vide d'entiers
    Renvoie l'indice de la 1ere occurrence du maximum du tableau*/
    assert (size > 0);
    int max = tab[0];
    int imax = 0;
    for (int i=0; i<size; i++) {
        if (tab[i] > max) {
            max = tab[i];
            imax = i;}}
    return imax;}

int main(){
    int test_tab[5] = {12,18,11,18,14};
    printf("Indice du max =%d\n",get_imax(test_tab,0));
    return 0;
}