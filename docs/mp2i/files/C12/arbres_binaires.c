#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

struct noeud
{
    struct noeud* sag;
    char value;
    struct noeud* sad;
};
typedef struct noeud noeud;
typedef noeud * arbre_binaire;

arbre_binaire cree_arbre( arbre_binaire g, int v, arbre_binaire d)
{
    noeud *n = malloc(sizeof(noeud));
    n->sag = g;
    n->value = v;
    n->sad = d;
    return n;
}

void write_edge(FILE * writer, arbre_binaire g)
{
    if (g->sag!=NULL)
    {
        fprintf(writer,"%c",g->value);
        fprintf(writer," -> ");
        fprintf(writer,"%c\n",g->sag->value);
        write_edge(writer,g->sag);
    }
    if (g->sag!=NULL)
    {
        fprintf(writer,"%c",g->value);
        fprintf(writer," -> ");
        fprintf(writer,"%c\n",g->sad->value);
        write_edge(writer,g->sad);
    }
}

void make_dot(arbre_binaire g)
{
    FILE * writer= fopen("temp.gv","w");
    fprintf(writer, "digraph mygraph {\n");
    write_edge(writer,g);
    fprintf(writer,"}\n");
    printf("Return value de dot =%d\n",system("dot temp.gv -Tjpg | display"));
    sleep(1);
    system("eog \"temp.png\"");
    //system("rm \"test.png\"");
    //system("rm \"test.gv\"");
}




int main()
{
    arbre_binaire c = cree_arbre(NULL,'c',NULL);
    arbre_binaire b = cree_arbre(NULL,'b',NULL);
    arbre_binaire a = cree_arbre(b, 'a', c);
    make_dot(a);
}