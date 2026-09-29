#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct objet_s
{
    char nom[15];
    int valeur;
    double poids;
};
typedef struct objet_s objet;


void vp(objet objets[], bool combinaison[], int n, int *valeur, double *poids)
{
    *valeur = 0;
    *poids = 0;
    for (int i = 0; i < n; i++)
    {
        if (combinaison[i])
        {
            *valeur += objets[i].valeur;
            *poids += objets[i].poids;
        }
    }
}

bool *brute(objet objets[], int n, double pmax)
{
    // Renvoie la combinaison optimale pour le sac à dos avec n objets et un sac de pmax
    bool test[n];
    int t;
    int vc;
    double pc;
    int vmax = 0;
    bool *sol = malloc(sizeof(bool) * n);
    for (int i = 0; i < 256; i++)
    {
        t = i;
        for (int j = 0; j < 8; j++)
        {
            test[j] = t % 2;
            t = t / 2;
        }
        vp(objets, test, 8, &vc, &pc);
        if (pc <= pmax)
        {
            if (vc > vmax)
            {
                vmax = vc;
                for (int k = 0; k < 8; k++)
                {
                    sol[k] = test[k];
                }
            }
        }
    }
    return sol;
}

int main()
{
    objet tobj0 = {.nom = "Hamburger", .valeur = 180, .poids = 0.3};
    objet tobj1 = {.nom = "Marteau", .valeur = 2050, .poids = 4.1};
    objet tobj2 = {.nom = "Parapluie", .valeur = 280, .poids = 0.6};
    objet tobj3 = {.nom = "Ballon", .valeur = 810, .poids = 1.7};
    objet tobj4 = {.nom = "Clé", .valeur = 990, .poids = 2.0};
    objet tobj5 = {.nom = "Sapin", .valeur = 1275, .poids = 2.9};
    objet tobj6 = {.nom = "Chapeau", .valeur = 2570, .poids = 5.7};
    objet tobj7 = {.nom = "Guitare", .valeur = 920, .poids = 2.1};
    objet objets[8] = {tobj0, tobj1, tobj2, tobj3, tobj4, tobj5, tobj6, tobj7};
    bool *sol = brute(objets, 8, 8);
    for (int i=0;i<8;i++)
    {
        if (sol[i])
        {
            printf("%s \n", objets[i].nom);
        }
    }
}