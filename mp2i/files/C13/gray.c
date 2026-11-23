#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
struct gray_s
{
    bool *compteur;
    bool parite;
    int taille;
};
typedef struct gray_s gray;

gray cree(int size)
{
    gray g;
    g.compteur = malloc(sizeof(bool) * size);
    g.parite = true;
    g.taille = size;
    for (int i=0;i<size;i++)
    {
        g.compteur[i]=false;
    }
    return g;
}

int dernier1(gray g)
{
    for (int i=g.taille-1;i>=0;i--)
    {
        if (g.compteur[i])
        {
            return i;
        }
    }
    return -1;
}

bool ajoute(gray *g)
{
    int inv;
    if (g->parite)
    {
        inv = g->taille - 1;
    }
    else
    {
        inv = dernier1(*g)-1;
        if (inv<0)
        {
            return false;
        }
    }
    g->compteur[inv] = !g->compteur[inv];
    g->parite = !g->parite;
    return true;
}

bool incremente(bool compteur[], int n)
{
    int idx = n - 1;
    while (idx >= 0 && compteur[idx])
    {
        compteur[idx--] = false;
    }
    if (idx == -1)
    {
        for (int i = 0; i < n; i++)
        {
            compteur[i] = true;
        }
        return false;
    }
    compteur[idx] = 1;
    return true;
}

void affiche(bool compteur[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (compteur[i])
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc!=2)
    {
        printf("Donner la taille des compteurs en argument \n");
        return 1;
    }
    int size = atoi(argv[1]);
    gray g = cree(size);
    double st = (double)clock()/CLOCKS_PER_SEC;
    while (ajoute(&g)) {};
    double et = (double)clock()/CLOCKS_PER_SEC;
    printf("Enumération de Gray, terminée en %lf !\n",et-st);
    bool compteur[size];
    for (int i=0;i<size;i++)
    {
        compteur[size] = false;
    }
    st = (double)clock()/CLOCKS_PER_SEC;
    while (incremente(compteur,size)) {};
    et = (double)clock()/CLOCKS_PER_SEC;
    printf("Enumération classique, terminée en %lf !\n",et-st);
}