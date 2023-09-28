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

#define LARGEUR 5
#define HAUTEUR 5

const char ENTETE[] = "P1\n";

bool dans_carte(int l, int c)
{
    return (l*LARGEUR+c >= 0) && (l*LARGEUR+c < HAUTEUR*LARGEUR);
}

int compte_voisins(bool etat[], int lig, int col)
{
    int cpt = 0;
    for (int i = lig - 1; i < lig + 2; i++)
        for (int j = col - 1; j < col + 2; j++)
            if ((lig != i || col != j) && dans_carte(i, j) && etat[i][j])
            {
                cpt++;
            }
    return cpt;
}

bool (*evolution(bool etat[HAUTEUR][LARGEUR]))[HAUTEUR]
{
    bool(*nouvel_etat)[LARGEUR] = malloc(sizeof(nouvel_etat) * HAUTEUR);
    int nb_voisins;
    for (int i = 0; i < LARGEUR; i++)
    {
        for (int j = 0; j < HAUTEUR; j++)
        {
            nb_voisins = compte_voisins(etat, i, j); 
            if (etat[i][j])
            {
                if (nb_voisins == 2 || nb_voisins == 3)
                {
                    nouvel_etat[i][j] = true;
                }
                else
                {
                    nouvel_etat[i][j] = false;
                }
            }
            else
            {
                if (nb_voisins==3)
                {
                    nouvel_etat[i][j] = true;
                }
                else
                {
                    nouvel_etat[i][j] = false;
                }
            }
        }
    }
    return nouvel_etat;
}

void set(bool etat[LARGEUR][HAUTEUR], bool nouvel_etat[LARGEUR][HAUTEUR])
{
     for (int i = 0; i < LARGEUR; i++)
    {
        for (int j = 0; j < HAUTEUR; j++)
        {etat[i][j] = nouvel_etat[i][j];
        }
    }
}

void affiche(bool etat[LARGEUR][HAUTEUR])
{
     for (int i = 0; i < LARGEUR; i++)
    {
        for (int j = 0; j < HAUTEUR; j++)
        {if (etat[i][j])
        printf("*");
        else
        printf(".");
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    bool(*etat)[LARGEUR] = malloc(sizeof(etat) * HAUTEUR);
    bool (*nouvel_etat)[LARGEUR];
    srand(time(NULL));
     for (int i = 0; i < LARGEUR; i++)
    {
        for (int j = 0; j < HAUTEUR; j++)
        {etat[i][j] = rand()%2;}}
    for (int i=0; i<10; i++)
    {affiche(etat);
    nouvel_etat = evolution(etat);
    set(etat,nouvel_etat);
    free(nouvel_etat);
    }
    free(etat);
}