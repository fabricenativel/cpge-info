#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct maillon
{
    int valeur;
    struct maillon *suivant;
};
typedef struct maillon maillon;
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

void ajouter_errone(liste_circulaire *lc, int val)
{
    maillon *nouveau = malloc(sizeof(maillon));
    nouveau->valeur = val;
    nouveau->suivant = (*lc)->suivant;
    (*lc)->suivant = nouveau;
    *lc = nouveau;
}

int retirer(liste_circulaire *f)
{
    int res = ((*f)->suivant)->valeur;
    maillon *old = (*f)->suivant;
    if (((*f)->suivant) == *f)
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

int longueur(liste_circulaire lc){
    if (est_vide(lc)){
        return 0;}
    else {
        liste_circulaire start = lc;
        int nb = 1;
        while (lc->suivant != start){
            nb += 1;
            lc = lc->suivant;}
        return nb;}
}

void view(liste_circulaire lc)
{
    printf("Longueur = %d\n", longueur(lc));
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
    liste_circulaire f = NULL;
    ajouter(&f, 3);
    ajouter(&f, 7);
    ajouter(&f, 4);
    ajouter(&f, 12);
    view(f);
    int x = retirer(&f);
    view(f);
    x = retirer(&f);
    view(f);
    x = retirer(&f);
    view(f);
    x = retirer(&f);
    view(f);
}