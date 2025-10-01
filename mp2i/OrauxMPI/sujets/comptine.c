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

bool est_vide(liste_circulaire f)
{
    return (f == NULL);
}

void ajouter(liste_circulaire *lc, int v)
{
    maillon *nm = malloc(sizeof(maillon));
    nm->valeur = v;
    if (est_vide(*lc))
    {
        nm->suivant = nm;
    }
    else
    {
        nm->suivant = (*lc)->suivant;
        (*lc)->suivant = nm;
    }
    *lc = nm;
}

liste_circulaire creer_cercle(int n)
{ // initialise une liste circulaire avec n maillons contenant les valeurs de 0 à n-1
    liste_circulaire cercle = NULL;
    for (int i = 0; i < n; i++)
    {
        ajouter(&cercle, i);
    }
    return cercle;
}

int enleve(liste_circulaire *f)
{
    int res = ((*f)->suivant)->valeur;
    maillon *old = (*f)->suivant;
    if ((*f)->suivant == *f)
    {
        *f = NULL;
    }
    else
    {
        (*f)->suivant = ((*f)->suivant)->suivant;
    }
    free(old);
    return res;
}

void avance(liste_circulaire *f, int s)
{

    if (!est_vide(*f))
    {
        for (int i = 0; i < s; i++)
        {
            *f = (*f)->suivant;
        }
    }
}

void view(liste_circulaire lc)
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

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <nombre d'enfants> <nombre de syllabes>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int n = atoi(argv[1]);
    int s = atoi(argv[2]);
    liste_circulaire cercle = creer_cercle(n);
    for (int i = 0; i < n - 1; i++)
    {
        avance(&cercle, s);
        enleve(&cercle);
        view(cercle);
    }
    view(cercle);
}