#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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
    if (a == NULL)
    {
        return 0;
    }
    return 1 + taille(a->sag) + taille(a->sad);
}

bool est_vide(ab a)
{
    return (a == NULL);
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
    if (a != NULL)
    {
        printf("%d ", a->valeur);
        prefixe(a->sag);
        prefixe(a->sad);
    }
}

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

ab arbre_aleatoire(int n, int val)
{
    if (n == 0)
    {
        return NULL;
    }
    int k = rand() % n;
    ab sag = arbre_aleatoire(k, val + 1);
    ab sad = arbre_aleatoire(n - k - 1, val + k + 1);
    return cree_arbre(sag, val, sad);
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
    for (int i = 0; i < n; i++)
    {
        insere_noeud(&t, i);
    }
    return t;
}

int main()
{
    ab t = aleatoire(10);
    srand(time(NULL));
    insere_noeud(&t, 11);
    view(t);
    printf("Taille de l'arbre = %d\n", taille(t));
    prefixe(t);
    libere(&t);
    printf("Taille de l'arbre = %d\n", taille(t));
    prefixe(t);
    printf("\n");
}