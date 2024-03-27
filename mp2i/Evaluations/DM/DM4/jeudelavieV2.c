/*
 * une cellule vide ayant 3 voisines devient une cellule vivante
 * une cellule vivante le reste si elle a 2 ou 3 voisines, sinon elle meurt
 */

/*
V2 : On alloue le tableau à 2 dimensions comme un tableau pointeurs, chaque pointeur pointe sur une ligne
avantages : 
- syntaxe plus simple, un tableau est un pointeur de pointeurs donc un bool** ici (simplifie les signatures de fonctions)
- on peut avoir des lignes différentes (ex : tableau de chaines de caractères)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

const int LARGEUR=4;
const int HAUTEUR=4;

const char ENTETE[] = "P1\n";

bool dans_carte(int l, int c)
{
    return (l >= 0) && (l < HAUTEUR) && (c >= 0) && (c < LARGEUR);
}

int compte_voisins(bool **etat, int lig, int col)
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

bool** evolution(bool **etat)
{
    bool**nouvel_etat= malloc(sizeof(bool*) * HAUTEUR);
    for (int i=0;i<LARGEUR;i++)
    {
        nouvel_etat[i] = malloc(sizeof(bool)* LARGEUR);
    }
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

void set(bool **etat, bool **nouvel_etat)
{
     for (int i = 0; i < LARGEUR; i++)
    {
        for (int j = 0; j < HAUTEUR; j++)
        {etat[i][j] = nouvel_etat[i][j];
        }
    }
}

void affiche(bool **etat)
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
    bool**etat= malloc(sizeof(bool*) * HAUTEUR);
    for (int i=0;i<LARGEUR;i++)
    {
        etat[i] = malloc(sizeof(bool)* LARGEUR);
    }
    bool **nouvel_etat;
    srand(time(NULL));
     for (int i = 0; i < LARGEUR; i++)
    {
        for (int j = 0; j < HAUTEUR; j++)
        {etat[i][j] = false;}}
    etat[0][3] = true;
    etat[1][1] = true;
    etat[1][2] = true;
    etat[2][2] = true;
    etat[3][0] = true;
    for (int i=0; i<20; i++)
    {affiche(etat);
    nouvel_etat = evolution(etat);
    set(etat,nouvel_etat);
    for (int j = 0; j < HAUTEUR; j++)
    {free(nouvel_etat[j]);}
    free(nouvel_etat);
    }
    for (int j = 0; j < HAUTEUR; j++)
    {free(etat[j]);}
    free(etat);
}