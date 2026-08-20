#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//--8<-- [start:struct]
struct graphe
{
    int taille; // |S|
    bool *madj; // matrice linéarisée (à allouer)
};
typedef struct graphe graphe;
//--8<-- [end:struct]

graphe cree_graphe(int n)
{
    graphe g;
    g.taille = n;
    g.madj = malloc(sizeof(bool) * n * n);
    for (int i = 0; i < n * n; i++)
    {
        g.madj[i] = false;
    }
    return g;
}

void detruit_graphe(graphe g)
{
    free(g.madj);
}

void print_graphe(graphe g)
{
    int n = g.taille;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g.madj[i * n + j])
            {
                printf("1 ");
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void cree_arete(graphe g, int i, int j)
{
    g.madj[i * g.taille + j] = true;
    g.madj[j * g.taille + i] = true;
}

//--8<-- [start:visualise]
// Visualisation du graphe g
void visualise(graphe g)
{
    int n = g.taille;
    FILE *writer = fopen("temp.gv", "w");
    fprintf(writer, "graph mygraph {\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (g.madj[i * n + j])
            {
                fprintf(writer, "%d -- %d\n", i, j);
            }
        }
    }
    fprintf(writer, "}\n");
    fclose(writer);
    system("xdot temp.gv &");
}
//--8<-- [end:visualise]

int main()
{
    graphe g = cree_graphe(5);
    cree_arete(g, 1, 3);
    cree_arete(g, 2, 4);
    cree_arete(g, 0, 1);
    cree_arete(g, 0, 2);
    cree_arete(g, 0, 3);
    print_graphe(g);
    visualise(g);
    detruit_graphe(g);
}