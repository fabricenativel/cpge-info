#include <stdio.h>
#include <string.h>

// Renvoie l'indice de la première occurence de motif dans chaine (-1 si absent)
int naive(char *motif, char *texte)
{
    int lm = strlen(motif);
    int lt = strlen(texte);
    for (int i = 0; i < lt - lm; i++)
    {
        if (strncmp(motif, &texte[i],lm) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("A utiliser en donnant le texte et le motif à chercher\n");
    }
    else
    {
        printf("Première occurence en %d\n", naive(argv[1], argv[2]));
    }
}