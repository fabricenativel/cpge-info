#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define  TYPE char
struct maillon
{
    TYPE valeur;
    struct maillon * suivant;
};
typedef struct maillon maillon;
typedef maillon* liste;

liste cree_liste()
{
    liste l= NULL;
    return l;
}

void ajout(liste *l, TYPE v)
{
    liste nl=malloc(sizeof(maillon));
    nl->suivant = *l;
    nl->valeur =v;
    *l = nl;
}

void ajoutdouble(liste *l, TYPE val, int idx)
{
    liste prec = *l;
    liste suiv = (*l)->suivant;
    maillon *nm1 = malloc(sizeof(maillon));
    maillon *nm2 = malloc(sizeof(maillon));
    nm1->valeur = val;
    nm2->valeur = val;
    for (int i=0;i<idx-1;i++)
    {
       prec = suiv;
       suiv = suiv->suivant;
    }
    prec->suivant = nm1;
    nm1->suivant = nm2;
    nm2->suivant = suiv;
}
void supprime(liste *l)
{
    if (l!=NULL)
    {
        liste ls = (*l)->suivant;
        free(*l);
        *l = ls;
    }
}

void view_list(liste l)
{
    printf("-> ");
    while (l!=NULL)
    {
        printf("%c -> ",l->valeur);
        l = l->suivant;
    }
    printf("\n");
}

void savel(liste l, char filename[])
{
    FILE * writer = fopen(filename,"w");
    while (l!=NULL)
    {
        fputc(l->valeur,writer);
        l=l->suivant;
    }
    fclose(writer);
}


void makepb(liste *l, int pbsize)
{
    char c;
    int pos;
    int size = 8;
    for (int i=0;i<pbsize;i++)
    {
        c = 65+rand()%26;
        pos = rand()%size;
        if (pos==0)
        {
            ajout(l,c);
            ajout(l,c);
        }
        else
        {
            ajoutdouble(l,c,pos);
        }
        size = size+2;
    }
}

int main()
{   srand(time(NULL));
    liste l = cree_liste();
    char mot[] = "CONCOURS";
    for (int i=0; i<strlen(mot);i++)
    {
        ajout(&l,mot[strlen(mot)-i-1]);
    }
    makepb(&l,5000);
    savel(l,"pb.txt");
}