#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void echange(int tab[], int i, int j)
{
    int temp;
    temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

// Affiche un tableau
void affiche(int tab[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("%d ", tab[i]);
    }
}

// Prend en entrée un tableau (ne contenant que les valeurs 1, 2 et 3)
// Ne renvoie rien 
// Réarrange les éléments du tableau de façon à avoir les 1 puis les 2 et les 3
void drapeau_hollandais(int tab[], int taille)
{
    int i1 = 0;
    int i2 = taille - 1;
    int i3 = taille - 1;
    while (i1 <= i2){
        if (tab[i1] == 1){
            i1 = i1 + 1;}
        else{
            if (tab[i1] == 2){
                echange(tab, i1, i2);
                i2 = i2 - 1;}
            else{
                echange(tab, i1, i2);
                echange(tab, i2, i3);
                i3 = i3 - 1;
                i2 = i2 - 1;}
        }
    }
}

// Génère un tableau aléatoire de 1, 2, 3
int *genere(int taille)
{
    int *tab = malloc(sizeof(int) * taille);
    for (int i = 0; i < taille; i++)
    {
        tab[i] = 1 + rand() % 3;
    }
    return tab;
}

int main()
{
    srand(time(NULL));
    int test[100];
    for (int i=0;i<100;i++)
    {
        test[i] = 1 + rand()%3;
    }
    drapeau_hollandais(test, 100);
    affiche(test,100);
    printf("\n");
    //free(test);
}