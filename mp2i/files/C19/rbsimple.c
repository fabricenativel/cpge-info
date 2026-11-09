#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>


uint32_t hash(char *m, int len)
{
    uint32_t h = 0;
    for (int i = 0; i < len; i++)
    {
        h +=  m[i];
    }
    return h;
}

int rabinkarp(char *motif, char *texte, int *nbcoll)
{
    int lm = strlen(motif);
    int lt = strlen(texte);
    uint64_t hashmotif = hash(motif, lm);
    uint32_t current_hash = hash(&texte[0], lm);
    int occ = 0;
    int idx = 0;
    while (idx < lt - lm)
    {
        if (hashmotif == current_hash)
        {
            *nbcoll = *nbcoll + 1;
            if (strncmp(motif, &texte[idx], lm) == 0)
            {
                occ++;
            }
        }
        current_hash = (current_hash - texte[idx] + texte[idx+lm]);
        idx++;
    }
    return occ;
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
        int nbcoll = 0;
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
            nbocc = rabinkarp(argv[1], texte, &nbcoll);
            printf("Nombre d'occurrences trouvées = %d (avec %d collisions) \n", nbocc, nbcoll);
        }
    }
}