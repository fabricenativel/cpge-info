#include <stdio.h>
#include <stdlib.h>

struct noeud
{
    struct noeud *sag;
    int valeur;
    struct noeud *sad;
};
typedef struct noeud noeud;
typedef noeud *ab;

int ninv = 0;

ab cree_arbre(ab g, int v, ab d)
{
    noeud *n = malloc(sizeof(noeud));
    n->sag = g;
    n->valeur = v;
    n->sad = d;
    return n;
}

int taille(ab a)
{
    if (a==NULL)
    { return 0;}
    return 1 + taille(a->sag) + taille(a->sad);;
}

void write_edge(FILE *writer, ab g)
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

void view(ab g)
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

void prefixe(ab a)
{
    if (a!=NULL)
    {
        printf("%d ",a->valeur);
        prefixe(a->sag);
        prefixe(a->sad);
    }
}

int main()
{
    ab n7 = cree_arbre(NULL, 7, NULL);
    ab n5 = cree_arbre(NULL, 5, n7);
    ab n4 = cree_arbre(NULL, 4, NULL);
    ab n3 = cree_arbre(n4, 3, NULL);
    ab n9 = cree_arbre(n5, 9, n3);
    view(n9);
    printf("Taille de l'arbre = %d\n",taille(n9));
    prefixe(n9);
    printf("\n");
}