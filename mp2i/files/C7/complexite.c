#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

bool recherche_simple(int elt, int tab[], int size){
    for (int i = 0; i < size; i = i + 1){
        if (tab[i] == elt)
        {return true;}}
    return false;}

bool recherche_dichotomique(int elt, int tab[], int size){
    int deb = 0;
    int fin = size - 1;
    int milieu;
    while (fin - deb >= 0){
        milieu = (deb + fin) / 2;
        if (tab[milieu] == elt){
            return true;}
        else{
            if (tab[milieu] < elt){
                deb = milieu + 1;}
            else{
            fin = milieu - 1;}}
    }
    return false;}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    if (argc != 2)
    {
        printf("Il faut donner la taille sur la ligne de commande");
    }
    else
    {
        int size = atoi(argv[1]);
        int *tab = malloc(sizeof(int) * (long unsigned int)size);
        clock_t start, stop;
        int res1, res2;
        tab[0] = 1;
        for (int i = 1; i < size; i++)
        {
            tab[i] = tab[i - 1] + rand() % 2 + 1;
        }
        int elt = rand() % tab[size - 1];
        start = clock();
        res1 = recherche_simple(elt, tab, size);
        stop = clock();
        printf("Temps en recherche simple = %lf (%d)\n", (double)(stop - start) / CLOCKS_PER_SEC, res1);
        start = clock();
        res2 = recherche_dichotomique(elt, tab, size);
        stop = clock();
        printf("Temps en recherche dichotomique = %lf (%d) \n", (double)(stop - start) / CLOCKS_PER_SEC, res2);
        free(tab);
    }
}