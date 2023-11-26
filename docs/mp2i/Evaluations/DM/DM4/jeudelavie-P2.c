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
#include <string.h>

#define LARGEUR 57
#define HAUTEUR 37
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
        printf("O");
        else
        printf(".");
        }
        printf("\n");
    }
    printf("\n");
}


void cree_image(bool etat[], char* nom_image)
{
    FILE* writer = fopen(nom_image,"w");
    fprintf(writer,"%s","P1\n");
    fprintf(writer,"%d %d\n",LARGEUR,HAUTEUR);
    for (int i=0;i<HAUTEUR;i++)
    {
        for (int j=0;j<LARGEUR;j++)
        {
            if (etat[i*LARGEUR+j])
            {fprintf(writer,"%c",'1');}
            else
            {fprintf(writer,"%c",'0');}
        }
        fprintf(writer,"%s","\n");
    }
    fclose(writer);
}

char * make_str(int n, int size)
{
    char * res = malloc(sizeof(char)*(size+5));
    for (int i=0; i<size; i++)
    {
        res[size-i-1] = '0' + n%10;
        n =n / 10;
    }
    res[size] = '.';
    res[size+1] = 'b';
    res[size+2] = 'p';
    res[size+3] = 'm';
    res[size+4] = '\0';
    return res;
}

bool * evolution(bool * etat, int nb_etapes, bool voir, bool make_img)
{
    bool *ancien = malloc(sizeof(bool)*TAILLE);
    bool *nouveau;
    char * fname;
    copie_etat(ancien,etat);
    for (int i=0; i<nb_etapes; i++)
    {
        nouveau = etat_suivant(ancien);
        copie_etat(ancien,nouveau);
        if (voir)
        {
            affiche(nouveau);
        }
        if (make_img)
        {   
            fname = make_str(i,4);
            cree_image(nouveau,fname);
            free(fname);
        }
        if (i!=nb_etapes-1)
        { free(nouveau);}
    }
    free(ancien);
    return nouveau;
}

int compte_vivant(bool *etat)
{
    int vivant = 0;
    for (int i=0;i<HAUTEUR;i++)
    {
        for (int j=0;j<LARGEUR;j++)
        {
            if (etat[i*LARGEUR+j])
            {
                vivant +=1;
            }
        }
    }
    return vivant;
}

bool* read(char * filename)
{
    bool *etat = malloc(sizeof(bool)*TAILLE);
    FILE * reader = fopen(filename,"r");
    char cell;
    for (int i=0;i<HAUTEUR;i++)
    {
        for (int j=0;j<LARGEUR;j++)
        {
            cell = fgetc(reader);
            if (cell=='.')
            {
                etat[i*LARGEUR+j] = false;
            }
            else
            {
                etat[i*LARGEUR+j] = true;
            }
        }
        fgetc(reader);
    }
    return etat;
}


int main()
{
    bool *resultat;
    int nb = 33;
    bool *etat = read("glidergun.cells");
    printf("Fichier lu, il contient %d cellules vivantes \n",compte_vivant(etat));
    affiche(etat);
    cree_image(etat,"img0.pbm");
    resultat = evolution(etat, nb, false, true);
    printf("Il y a %d cellules vivantes après %d etapes \n",compte_vivant(resultat),nb);
    free(resultat);
    free(etat);
}