#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

struct element_s
{
    uint8_t repetition;
    char caractere;
};
typedef struct element_s element;

struct texte_compresse_s
{
    element *elt;
    int taille;
};
typedef struct texte_compresse_s texte_compresse;

int get_taille(char *texte)
{
    if (texte[0] == '\0')
    {
        return 0;
    }
    int t = 1;
    int pos = 1;
    while (texte[pos] != '\0')
    {
        if (texte[pos] != texte[pos - 1])
        {
            t += 1;
        }
        pos = pos + 1;
    }
    return t;
}

texte_compresse encode(char *texte)
{
    texte_compresse tc;
    tc.taille = get_taille(texte);
    if (tc.taille == 0)
    {
        tc.elt = NULL;
        return tc;
    }
    tc.elt = malloc(sizeof(element) * tc.taille);
    char car_courant = texte[0];
    int rep = 1;
    int pos = 1;
    int t = 0;
    while (texte[pos] != '\0')
    {
        if (texte[pos] == car_courant)
        {
            rep = rep + 1;
        }
        else
        {
            tc.elt[t].caractere = car_courant;
            tc.elt[t].repetition = rep;
            rep = 1;
            car_courant = texte[pos];
            t = t + 1;
        }
        pos += 1;
    }
    tc.elt[t].caractere = car_courant;
    tc.elt[t].repetition = rep;
    return tc;
}

void voir(texte_compresse tc)
{
    for (int i = 0; i < tc.taille; i++)
    {
        printf("(%d,%c)",tc.elt[i].repetition,tc.elt[i].caractere);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Utilisation : %s <texte>\n", argv[0]);
        return EXIT_FAILURE;
    }
    texte_compresse tc = encode(argv[1]);
    voir(tc);
    free(tc.elt);
    return EXIT_SUCCESS;
}