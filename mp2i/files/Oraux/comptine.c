#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct maillon_s
{
    int valeur;
    struct maillon_s *suivant;
};
typedef struct maillon_s maillon;
typedef maillon *liste_circulaire;

void affiche(liste_circulaire lc)
{
    if (est_vide(lc))
    {
        printf("NULL");
    }
    else
    {
        liste_circulaire start = lc->suivant;
        printf("%d -> ", start->valeur);
        lc = lc->suivant;
        while (lc->suivant != start)
        {
            printf("%d -> ", lc->suivant->valeur);
            lc = lc->suivant;
        }
    }
    printf("\n");
}

int main()
{
   
}