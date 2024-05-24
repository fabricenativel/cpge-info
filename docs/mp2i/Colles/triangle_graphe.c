#include <stdio.h>
#include <stdbool.h>

// Nombre maximal de sommets
#define NMAX 100
// La matrice d'adjacence du graphe
typedef bool graphe[NMAX][NMAX];

struct triangle
{
    int a;
    int b;
    int c;
};
typedef struct triangle triangle;

void cree_arete(graphe g, int i, int j){
    g[i][j] = true;
    g[j][i] = true;}

bool est_triangle(graphe g, triangle t)
{
    return g[t.a][t.b] && g[t.b][t.c] && g[t.a][t.c];
}

void affiche_triangle(triangle t)
{
    printf("{%d,%d,%d}\n", t.a, t.b, t.c);
}

void liste_triangle(graphe g, int n)
{
    triangle t;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                t = (triangle){.a = i, .b = j, .c = k};
                if (est_triangle(g, t))
                {
                    affiche_triangle(t);
                }
            }
        }
    }
}

int main()
{
    graphe g;
    cree_arete(g, 1, 2);
    cree_arete(g, 1, 4);
    cree_arete(g, 1, 5);
    cree_arete(g, 2, 3);
    cree_arete(g, 2, 4);
    cree_arete(g, 2, 5);
    cree_arete(g, 3, 5);
    cree_arete(g, 4, 5);
    liste_triangle(g, 6);
}
