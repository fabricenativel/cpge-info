#include <stdio.h>
#include <stdlib.h>

//--8<-- [start:struct]
struct maillon{
    int valeur;
    struct maillon* suivant;};
typedef struct maillon maillon;
typedef maillon* liste;

struct graphe{
    int taille;
    liste* ladj;};
typedef struct graphe graphe;
//--8<-- [end:struct]


void view_list(liste l)
{
    printf("-> ");
    while (l!=NULL)
    {
        printf("%i -> ",l->valeur);
        l = l->suivant;
    }
    printf("null \n");
}

liste cree_liste()
{
    liste l= NULL;
    return l;
}

void ajout(liste *l, int v)
{
    liste nl=malloc(sizeof(maillon));
    nl->suivant = *l;
    nl->valeur =v;
    *l = nl;
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

void detruit(liste *l)
{
    liste oh;
    while (*l!=NULL)
    {   
        oh = *l;
        *l = (*l)->suivant;
        free(oh);
    }
}

graphe init_graphe(int size)
{
    graphe g;
    g.taille = size;
    g.ladj = malloc(sizeof(liste)*size);
    for (int i=0;i<size;i++)
    {
        g.ladj[i] = cree_liste();
    }
    return g;
}

void cree_arete(graphe g, int i, int j)
{
    ajout(&(g.ladj[i]),j);
}

void affiche_graphe(graphe g)
{
    for (int i=0;i<g.taille;i++)
    {
        printf("%d : ",i);
        view_list(g.ladj[i]);
    }
    
}

//--8<-- [start:visualise]
void visualise(graphe g)
{
    FILE *writer = fopen("temp.gv", "w");
    fprintf(writer, "digraph mygraph {\n");
    maillon * mc;
    int n = g.taille;
    for (int i=0; i<n; i++)
    {
        mc = g.ladj[i];
        while (mc!=NULL)
        {
           {fprintf(writer,"%d -> %d\n",i,mc->valeur);}
            mc=mc->suivant;
        }
    }
    fprintf(writer, "}\n");
    fclose(writer);
    system("xdot temp.gv &");
}
//--8<-- [end:visualise]

int main()
{ graphe g = init_graphe(5);
    cree_arete(g, 1, 3);
    cree_arete(g, 2, 4);
    cree_arete(g, 0, 1);
    cree_arete(g, 0, 2);
    cree_arete(g, 0, 3);
    affiche_graphe(g);
    visualise(g);
}

