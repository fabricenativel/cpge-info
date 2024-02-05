#include <stdio.h>
#include <stdlib.h>

struct noeud
{
    struct noeud *sag;
    int valeur;
    struct noeud *sad;
};
typedef struct noeud noeud;
typedef noeud *abr;

int ninv = 0;

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

void write_edge(FILE *writer, abr g)
{
    if (g->sag != NULL)
    {
        fprintf(writer, "%d", g->valeur);
        fprintf(writer, " -> ");
        fprintf(writer, "%d\n", g->sag->valeur);
        write_edge(writer, g->sag);
    }
    else
    {
        fprintf(writer, "I%d [style=invis]\n", ninv);
        fprintf(writer, "%d -> I%d [style=invis]\n", g->valeur, ninv);
        ninv++;
    }
    fprintf(writer, "I%d [style=invis]\n", ninv);
    fprintf(writer, "%d -> I%d [style=invis]\n", g->valeur, ninv);
    ninv++;
    if (g->sad != NULL)
    {
        fprintf(writer, "%d", g->valeur);
        fprintf(writer, " -> ");
        fprintf(writer, "%d\n", g->sad->valeur);
        write_edge(writer, g->sad);
    }
    else
    {
        fprintf(writer, "I%d [style=invis]\n", ninv);
        fprintf(writer, "%d -> I%d [style=invis]\n", g->valeur, ninv);
        ninv++;
    }
}

void view(abr g)
{
    char buf[256];
    int n;
    FILE *writer = fopen("temp.gv", "w");
    FILE *imgwriter = fopen("temp.jpg", "wb");
    fprintf(writer, "digraph mygraph {\n");
    write_edge(writer, g);
    fprintf(writer, "}\n");
    fclose(writer);
    FILE *dotresult = popen("dot temp.gv -Tjpg", "r");
    if (dotresult == NULL)
    {
        printf("Bug !\n");
    }
    while ((n = fread(buf, 1, 256, dotresult)) != 0)
    {
        fwrite(buf, 1, n, imgwriter);
    }
    pclose(dotresult);
    fclose(imgwriter);
    system("eog temp.jpg &");
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

int main()
{
    abr g = NULL;
    insere(&g, 7);
    insere(&g, 5);
    insere(&g, 9);
    insere(&g, 2);
    insere(&g, 11);
    view(g);
    printf("\n");
}