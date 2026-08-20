#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define NB_CHAR 256

// La fonction de décalage
int *cree_decalage(char *motif)
{
    int lm = strlen(motif);
    int *decalage = malloc(sizeof(int) * NB_CHAR);
    for (int i = 0; i < NB_CHAR; i++)
    {
        decalage[i] = lm;
    }
    for (int i = 0; i < lm - 1; i++)
    {
        decalage[(int)motif[i]] = lm - i - 1;
    }
    return decalage;
}

int bmh(char *motif, char *texte, int *nbcmp)
{
    int *dec = cree_decalage(motif);
    int lt = strlen(texte);
    int lm = strlen(motif);
    int idx = 0;
    int im;
    int cpt = 0;
    while (idx < lt - lm + 1)
    {
        *nbcmp = *nbcmp + 1;
        im = lm - 1;
        while (im >= 0 && texte[idx + im] == motif[im])
        {
            im = im - 1;
            *nbcmp = *nbcmp + 1;
        }
        if (im < 0)
        {
            cpt++;
        }
        idx += dec[(int)texte[idx + lm - 1]];
    }
    return cpt;
}

bool appartient_bmh(char *motif, char *texte){
    int *dec = cree_decalage(motif);
    int lt = strlen(texte);
    int lm = strlen(motif);
    int idx = 0;
    int im;
    while (idx < lt - lm + 1){
        im = lm - 1;
        while (im >= 0 && texte[idx + im] == motif[im]){
            im = im - 1;}
        if (im < 0){
            return true;}
        idx += dec[(int)texte[idx + lm - 1]];}
    return false;}

// Affichage fonction décalage
void affiche(int dec[], int l)
{
    for (int i = 0; i < NB_CHAR; i++)
    {
        if (dec[i] != l)
        {
            printf("(%c : %d) ", i, dec[i]);
        }
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Donner le motif suivi du nom de fichier dans lequel cherché !\n");
    }
    else
    {
        char *texte = malloc(sizeof(char) * 2000000);
        FILE *reader = fopen(argv[2], "r");
        int i = 0;
        char tempc;
        int nbocc;
        int nbcmp = 0;
        if (reader == NULL)
        {
            printf("Le fichier n'a pas été trouvé \n");
        }
        else
        {
            while ((tempc = fgetc(reader)) != EOF)
            {
                texte[i++] = tempc;
            }
            printf("Lecture du fichier terminé \n");
            texte[i] = '\n';
            int *dec = cree_decalage(argv[1]);
            affiche(dec, strlen(argv[1]));
            nbocc = bmh(argv[1], texte, &nbcmp);
            printf("Nombre d'occurrences trouvées = %d (avec %d comparaisons) \n", nbocc, nbcmp);
            if (appartient_bmh(argv[1],texte)) {printf("Motif trouvé \n");} else {printf("Motif absent \n");}
        }
    }
}
