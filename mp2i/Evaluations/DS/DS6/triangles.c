#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct graphe_s
{
    int taille; // |S|
    int *madj; // matrice linéarisée (à allouer)
};
typedef struct graphe_s graphe;

graphe cree_graphe(int n)
{
    graphe g;
    g.taille = n;
    g.madj = malloc(sizeof(int) * n * n);
    for (int i = 0; i < n * n; i++)
    {
        g.madj[i] = 0;
    }
    return g;
}

int* produit_matriciel(int* a, int* b, int n)
{
    int *c = malloc(sizeof(int)*n*n);
    for (int i=0;i<n;i++)
    {
        for (int j=0; j<n; j++)
        {
            c[i*n+j] = 0;
            for (int k=0;k<n;k++)
            {
                c[i*n+j] += a[i*n+k]*b[n*k+j];
            }
        }
    }
    return c;
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

int nb_triangles(graphe g)
{
    int *m3 = produit(g.madj, g.madj, g.taille);
    m3 = produit(g.madj, m3, g.taille);
    int nb = 0;
    for (int i=0;i<g.taille;i++)
    {
        nb += m3[i*g.taille+i];
    }
    free(m3);
    return nb;
}


int main()
{
    graphe g = cree_graphe(5);
    cree_arete(g, 0, 1);
    cree_arete(g, 0, 3);
    cree_arete(g, 0, 4);
    cree_arete(g, 1, 2);
    cree_arete(g, 1, 3);
    cree_arete(g, 1, 4);
    cree_arete(g, 2, 4);
    cree_arete(g, 3, 4);
    print_graphe(g);
    visualise(g);
    int t = nb_triangles(g);
    printf("Nombre de triangles = %d\n", t);
    detruit_graphe(g);
}