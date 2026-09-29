#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Renvoie le candidat ayant la majorité absolue et -1 si aucun
int majorite_absolue(int vote[], int size){
    int nb_votes = 0;
    int candidat = 0;
    for (int i = 0; i < size; i++){
        if (nb_votes == 0){
            candidat = vote[i];
            nb_votes = 1;}
        else{
            if (vote[i] == candidat){
                nb_votes += 1;}
            else{
                nb_votes -= 1;}
        }
    }
    printf("Seul candidat possible = %d\n", candidat);
    // Vérification du candidat
    int nbc = 0;
    for (int i = 0; i < size; i++)
    {
        if (vote[i] == candidat)
        {
            nbc += 1;
        }
    }
    if (nbc > size / 2)
    {
        return candidat;
    }
    else
    {
        return -1;
    }
}

int *cree_tab(int nb_val, bool maj, int size)
{
    int nbc;
    int *res = malloc(sizeof(int) * nb_val);
    int numc = rand() % size;
    int val;
    if (maj)
    {
        nbc = nb_val / 2 + 1;
    }
    else
    {
        nbc = nb_val / 2 - 1;
    }
    for (int i = 0; i < nbc; i++)
    {
        res[i] = numc;
    }
    for (int i = nbc; i < size; i++)
    {
        while ((val = rand() % size) == numc)
        {
        }
        res[i] = val;
    }
    return res;
}

void echange(int tab[], int i, int j)
{
    int temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

void shuffle(int tab[], int size)
{
    int j;
    for (int i = 0; i < size; i++)
    {
        j = rand() % size;
        echange(tab, i, j);
    }
}

void affiche(int tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d - ", tab[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));
    int size = 1000;
    int *vote;
    vote = cree_tab(size, false, size);
    int maj = majorite_absolue(vote, size);
    shuffle(vote, size);
    printf("Candidat avec majorite absolue = %d \n", maj);
}