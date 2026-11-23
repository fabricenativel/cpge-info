#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//--8<-- [start:struct]
#define NMAX 100 // nombre maximal de sommets
// graphe[i][0] contient le degré du sommet i
// graphe[i][1..] est la liste d'adjacence du sommet i
typedef int graphe[NMAX][NMAX];
//--8<-- [end:struct]

void init_graphe(graphe g, int size)
{
    for (int i = 0; i < size; i++)
        g[i][0] = 0;
}

void cree_arete(graphe g, int i, int j)
{
    g[i][0]++;
    g[j][0]++;
    g[i][g[i][0]] = j;
    g[j][g[j][0]] = i;
}

void affiche_graphe(graphe g, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d --> [", i);
        for (int j = 1; j <= g[i][0]; j++)
        {
            printf("%d", g[i][j]);
            if (j != g[i][0])
            {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

//--8<-- [start:visualise]
void visualise(graphe g, int n)
{
    FILE *writer = fopen("temp.gv", "w");
    fprintf(writer, "graph mygraph {\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(writer, "%d\n", i);
        for (int j = 1; j <= g[i][0]; j++)
        {
            if (i > g[i][j])
            {
                fprintf(writer, "%d -- %d\n", i, g[i][j]);
            }
        }
    }
    fprintf(writer, "}\n");
    fclose(writer);
    system("xdot temp.gv &");
}
//--8<-- [end:visualise]

int degre(graphe g, int i)
{
    return g[i][0];
}

int main()
{
    graphe g;
    init_graphe(g, 6);
    cree_arete(g, 1, 3);
    cree_arete(g, 2, 4);
    cree_arete(g, 0, 1);
    cree_arete(g, 0, 2);
    cree_arete(g, 0, 3);
    affiche_graphe(g, 6);
    printf("Degré du sommet 0 : %d\n", degre(g, 0));
    visualise(g, 6);
}