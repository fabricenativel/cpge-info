#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define NB_CHAR 256

int derniere_occurrence(char c, char *motif)
{
    for (int i = strlen(motif) - 1; i >= 0; i--)
    {
        if (motif[i] == c)
        {
            return strlen(motif) - 1 - i;
        }
    }
    return strlen(motif);
}

// La fonction de décalage
int *cree_decalage(char *motif)
{
    int *decalage = malloc(sizeof(int) * NB_CHAR);
    for (int i = 0; i < NB_CHAR; i++)
    {
        decalage[i] = strlen(motif);
    }
    for (int i = 0; i < (int)strlen(motif); i++)
    {
        decalage[(int)motif[i]] = derniere_occurrence(motif[i], motif);
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
        if (texte[idx + lm - 1] == motif[lm - 1])
        {
            im = 2;
            while (im <= lm && texte[idx + lm - im] == motif[lm - im])
            {
                im++;
                *nbcmp = *nbcmp + 1;
            }
            if (im> lm)
            {
                cpt++;
            }
            idx += 1;
        }
        else
        {
            idx += dec[(int)texte[idx + lm - 1]];
        }
    }
    return cpt;
}

// Affichage fonction décalage
void affiche(int dec[], int l)
{
    for (int i = 0; i < 256; i++)
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
        }
    }
}
