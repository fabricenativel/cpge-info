#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Renvoie l'indice de la première occurence de motif dans chaine (-1 si absent)
int occurence(char *motif, char *texte)
{
    int lm = strlen(motif);
    int lt = strlen(texte);
    for (int i = 0; i < lt - lm; i++)
    {
        if (strncmp(motif, &texte[i], lm) == 0)
        {
            return i;
        }
    }
    return -1;
}

int naive(char *motif, char *texte, int *nbcmp)
{
    int lm = strlen(motif);
    int lt = strlen(texte);
    int idx = 0;
    int nbocc = 0;
    for (int i = 0; i < lt - lm; i++)
    {
        idx = 0;
        *nbcmp = *nbcmp+1;
        while (idx < lm && texte[i + idx] == motif[idx])
        {
            *nbcmp = *nbcmp+1;
            idx++;
        }
        if (idx == lm)
        {
            nbocc += 1;
        }
    }
    return nbocc;
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
            nbocc = naive(argv[1], texte, &nbcmp);
            printf("Nombre d'occurrences trouvées = %d (avec %d comparaisons) \n", nbocc, nbcmp);
        }
    }
}