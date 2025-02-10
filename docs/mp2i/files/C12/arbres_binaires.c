#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// --8<-- [start:struct]
struct noeud
{
    struct noeud *sag;
    int valeur;
    struct noeud *sad;
};
typedef struct noeud noeud;
typedef noeud *ab;
// --8<-- [end:struct]

// --8<-- [start:cree]
ab cree_arbre(ab g, int v, ab d)
{
    noeud *n = malloc(sizeof(noeud));
    {
        n->sag = g;
        n->valeur = v;
        n->sad = d;
        return n;
    }
}
// --8<-- [end:cree]

// --8<-- [start:taille]
int taille(ab a)
{
    if (a == NULL)
    {
        return 0;
    }
    return 1 + taille(a->sag) + taille(a->sad);
}
// --8<-- [end:taille]

bool est_vide(ab a)
{
    return (a == NULL);
}

// --8<-- [start:voir]
void write_edge(FILE *writer, ab g, int *ninv)
{
    if (g->sag != NULL)
    {
        fprintf(writer, "%d", g->valeur);
        fprintf(writer, " -> ");
        fprintf(writer, "%d\n", g->sag->valeur);
        write_edge(writer, g->sag, ninv);
    }
    else
    {
        fprintf(writer, "I%d [style=invis]\n", *ninv);
        fprintf(writer, "%d -> I%d [style=invis]\n", g->valeur, *ninv);
        (*ninv)++;
    }
    fprintf(writer, "I%d [style=invis]\n", *ninv);
    fprintf(writer, "%d -> I%d [style=invis]\n", g->valeur, *ninv);
    (*ninv)++;
    if (g->sad != NULL)
    {
        fprintf(writer, "%d", g->valeur);
        fprintf(writer, " -> ");
        fprintf(writer, "%d\n", g->sad->valeur);
        write_edge(writer, g->sad, ninv);
    }
    else
    {
        fprintf(writer, "I%d [style=invis]\n", *ninv);
        fprintf(writer, "%d -> I%d [style=invis]\n", g->valeur, *ninv);
        (*ninv)++;
    }
}

void view(ab g)
{
    FILE *writer = fopen("temp.gv", "w");
    int n = 0;
    fprintf(writer, "digraph mygraph {\n");
    write_edge(writer, g, &n);
    fprintf(writer, "}\n");
    fclose(writer);
    system("xdot temp.gv &");
}
// --8<-- [end:voir]

// --8<-- [start:prefixec]
void prefixe(ab a)
{
    if (a != NULL)
    {
        printf("%d ", a->valeur);
        prefixe(a->sag);
        prefixe(a->sad);
    }
}
// --8<-- [end:prefixec]

void libere(ab *a)
{
    ab sag;
    ab sad;
    if (*a != NULL)
    {
        sag = (*a)->sag;
        sad = (*a)->sad;
        libere(&sag);
        libere(&sad);
        free(*a);
        *a = NULL;
    }
}


void insere_noeud(ab *t, int v)
{
    if (*t == NULL)
    {
        *t = cree_arbre(NULL, v, NULL);
    }
    else
    {
        if (rand() % 2 == 0)
        {
            insere_noeud(&((*t)->sag), v);
        }
        else
        {
            insere_noeud(&((*t)->sad), v);
        }
    }
}

ab aleatoire(int n)
{
    ab t = NULL;
    int etiquette[n];
    int j;
    int temp;
    for (int i = 0; i < n; i++)
    {etiquette[i]=i;}
    for (int i=0; i<n;i++)
    {
        j = rand()%(i+1);
        temp = etiquette[i];
        etiquette[i] = etiquette[j];
        etiquette[j] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        insere_noeud(&t, etiquette[i]);
    }
    return t;
}

int main()
{
    srand(time(NULL));
    ab t = aleatoire(10);
    view(t);
    printf("Taille de l'arbre = %d\n", taille(t));
    prefixe(t);
    libere(&t);
    printf("Taille de l'arbre = %d\n", taille(t));
    prefixe(t);
    printf("\n");
}