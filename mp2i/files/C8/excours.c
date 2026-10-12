#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
struct maillon_s
{
    int valeur;
    struct maillon_s *suivant;
};
typedef struct maillon_s maillon;
typedef maillon *liste;

void affiche(liste l)
{
    while (l!=NULL)
    {
        printf("%d -> ", l->valeur); // raccourci de (*l).valeur
        l = l->suivant;
    }
    printf(" -> NULL \n");
}

void ajoute(int v, liste *l)
{
    // Créer le maillon contenant la nouvelle valeur
    maillon *m = malloc(sizeof(maillon));
    m->valeur = v;
    // Le suivant de ce maillon est l'ancienne tête
    m->suivant = *l;
    // Faire pointer la tête vers le nouveau maillon
    *l = m; 
}

int retire(liste *l)
{
    assert (*l != NULL);
    int res = (*l)->valeur;
    liste temp = (*l)->suivant;
    free(*l);
    *l = temp;
    return res;
}




int main()
{
    liste ma_liste = NULL;
    ajoute(42,&ma_liste);
    ajoute(20,&ma_liste);
    ajoute(13,&ma_liste);
    affiche(ma_liste);
    int r = retire(&ma_liste);
    affiche(ma_liste);
    printf("Element retiré : %d\n",r);
}
