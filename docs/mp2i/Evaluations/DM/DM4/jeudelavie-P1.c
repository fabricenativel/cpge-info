/*
 * une cellule vide ayant 3 voisines devient une cellule vivante
 * une cellule vivante le reste si elle a 2 ou 3 voisines, sinon elle meurt
 */

/*
V1 : On alloue le tableau à 2 dimensions comme un tableau de tableaux à une dimension
avantages : 
- un seul malloc et un seul free par tableau
- moins d'espace occupé qu'avec un tableau de pointeurs (chaque pointeur pointant sur une ligne)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LARGEUR 4
#define HAUTEUR 4
#define TAILLE HAUTEUR*LARGEUR


bool dans_carte(int l, int c)
{
    return (0<=l && l<HAUTEUR) && (0<=c && c<LARGEUR);
}

int compte_voisin(bool etat[], int lig, int col)
{
    int cpt = 0;
    for (int i = lig - 1; i < lig + 2; i++)
        for (int j = col - 1; j < col + 2; j++)
            if ((lig != i || col != j) && dans_carte(i, j) && etat[i*LARGEUR+j])
            {
                cpt++;
            }
    return cpt;
}

bool *etat_suivant(bool etat[])
{
    bool*nouvel_etat = malloc(sizeof(bool) * TAILLE);
    int nb_voisins;
    for (int i = 0; i < HAUTEUR; i++)
    {
        for (int j = 0; j < LARGEUR; j++)
        {
            nb_voisins = compte_voisin(etat, i, j); 
            if (etat[i*LARGEUR+j])
            {
                if (nb_voisins == 2 || nb_voisins == 3)
                {
                    nouvel_etat[i*LARGEUR+j] = true;
                }
                else
                {
                    nouvel_etat[i*LARGEUR+j] = false;
                }
            }
            else
            {
                if (nb_voisins==3)
                {
                    nouvel_etat[i*LARGEUR+j] = true;
                }
                else
                {
                    nouvel_etat[i*LARGEUR+j] = false;
                }
            }
        }
    }
    return nouvel_etat;
}

void copie_etat(bool etat1[], bool etat2[])
{
     for (int i = 0; i < HAUTEUR; i++)
    {
        for (int j = 0; j < LARGEUR; j++)
        {etat1[i*LARGEUR+j] = etat2[i*LARGEUR+j];
        }
    }
}

void affiche(bool etat[])
{
     for (int i = 0; i < HAUTEUR; i++)
    {
        for (int j = 0; j < LARGEUR; j++)
        {if (etat[i*LARGEUR+j])
        printf("#");
        else
        printf(".");
        }
        printf("\n");
    }
    printf("\n");
}

bool * evolution(bool * etat, int nb_etapes, bool voir)
{
    bool *ancien = malloc(sizeof(bool)*TAILLE);
    bool *nouveau;
    copie_etat(ancien,etat);
    for (int i=0; i<nb_etapes; i++)
    {
        nouveau = etat_suivant(ancien);
        copie_etat(ancien,nouveau);
        if (voir)
        {
            affiche(nouveau);
        }
        if (i!=nb_etapes-1)
        { free(nouveau);}
    }
    free(ancien);
    return nouveau;
}

int main()
{
    bool *resultat;
    bool etat[TAILLE] = {false,false,false,true,false,true,true,false,false,false,true,false,true,false,false,false};
    resultat = evolution(etat, 4, true);
    free(resultat);
}