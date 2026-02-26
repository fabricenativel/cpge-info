#include <stdio.h>
#include <stdlib.h>

//--8<-- [start:struct]
struct noeud
{
    struct noeud *sag;
    int valeur;
    struct noeud *sad;
};
typedef struct noeud noeud;
typedef noeud *abr;
//--8<-- [end:struct]

void insere(abr *g, int v)
{
    if (*g == NULL)
    {
        noeud *n = malloc(sizeof(noeud));
        n->valeur = v;
        n->sag = NULL;
        n->sad = NULL;
        *g = n;
    }
    else
    {
        if (v < (*g)->valeur)
        {
            insere(&((*g)->sag), v);
        }
        else
        {
            insere(&((*g)->sad), v);
        }
    }
}

int taille(abr a)
{
    if (a == NULL)
    {
        return 0;
    }
    return 1 + taille(a->sag) + taille(a->sad);
    ;
}
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

void prefixe(abr a)
{
    if (a != NULL)
    {
        printf("%d ", a->valeur);
        prefixe(a->sag);
        prefixe(a->sad);
    }
}

int minv(abr *g)
{
    if ((*g)->sag == NULL)
    {
        int t = (*g)->valeur;
        abr td = (*g)->sad;
        free(*g);
        *g=td;
        return t;
    }
    else {return minv (&(*g)->sag);}
}

void supprime(abr *g, int v)
{
    if (*g != NULL)
    {
        if (v < (*g)->valeur)
        {
            supprime(&((*g)->sag), v);
        }
        else if (v > (*g)->valeur)
        {
            supprime(&((*g)->sad), v);
        }
        else
        {
            if ((*g)->sag==NULL && (*g)->sad==NULL)
            {
                free(*g);
                *g = NULL;
            }
            else if ((*g)->sad==NULL) 
            {
                (*g) = (*g)->sag;
                free((*g)->sag);
            }
            else
            {
                int nv =  minv(&(*g)->sad);
                (*g)->valeur = nv;
            }
        }
    }
}

int main()
{
    abr g = NULL;
    insere(&g, 7);
    insere(&g, 5);
    insere(&g, 9);
    insere(&g, 2);
    insere(&g, 11);
    insere(&g, 10);
    insere(&g, 6);
    insere(&g, 8);
    supprime(&g,9);
    supprime(&g,7);
    supprime(&g,2);
    view(g);
    printf("\n");
}