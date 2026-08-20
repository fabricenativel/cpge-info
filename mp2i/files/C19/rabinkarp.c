#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t puissance(int a, int n)
{
    uint64_t p = 1;
    for (int i=0;i<n;i++)
    {
        p=p*a;
    }
    return p;
}

uint64_t hash(char *m, int len)
{
    uint64_t h = 0;
    for (int i = 0; i < len; i++)
    {
        h = 31 * h + m[i];
    }
    return h;
}

int rabinkarp(char *motif, char *texte, int *collisions)
{
    int lm = strlen(motif);
    int lt = strlen(texte);
    uint64_t hashmotif = hash(motif, lm);
    uint64_t current_hash = hash(&texte[0], lm);
    uint64_t powerlast = puissance(31,lm-1);
    int occ = 0;
    int idx = 0;
    *collisions = 0;
    while (idx < lt - lm)
    {
        if (hashmotif == current_hash)
        {
            if (strncmp(motif, &texte[idx], lm) == 0)
            {
                occ++;
            }
            else
            {
                *collisions = *collisions + 1;
            }
        }
        current_hash = (current_hash - texte[idx]*powerlast)*31 + texte[idx+lm];
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
        int collisions = 0;
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
            nbocc = rabinkarp(argv[1], texte, &collisions);
            printf("Nombre d'occurrences trouvées = %d (avec %d collisions) \n", nbocc, collisions);
        }
    }
}