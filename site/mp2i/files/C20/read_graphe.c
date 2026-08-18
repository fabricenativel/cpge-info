#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

struct graph_s
{
    int size;
    bool *mat;
    bool oriented;
};
typedef struct graph_s graph;

graph make_graphe(int n, bool or)
{
    bool *m = malloc(sizeof(bool) * n * n);
    if (m == NULL)
    {
        printf("Echec de l'allocation mémoire pour un graphe de taille %d \n", n);
    }
    graph g = {.size = n, .mat = m, .oriented = or};
    for (int i = 0; i < n * n; i++)
    {
        g.mat[i] = false;
    }
    return g;
}

void make_edge(graph g, int u, int v)
{
    g.mat[g.size * u + v] = true;
    if (!g.oriented)
    {
        g.mat[g.size * v + u] = true;
    }
}

graph read_graph(char *filename)
{
    FILE *reader = fopen(filename, "r");
    if (reader == NULL)
    {
        printf("Le fichier %s n'a pas été trouvé !\n", filename);
        exit(EXIT_FAILURE);
    }
    int n, edges, or;
    int u, v;
    fscanf(reader, "%d %d %d\n", &n, &edges, &or);
    printf("Le graphe à %d sommets et %d aretes\n", n, edges);
    graph g = make_graphe(n, (or == 1));
    for (int i = 0; i < edges; i++)
    {
        fscanf(reader, "%d %d\n", &u, &v);
        make_edge(g, u, v);
    }
    fclose(reader);
    return g;
}

int count_edges(graph g)
{
    int c = 0;
    int n = g.size;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g.mat[i * n + j])
            {
                c++;
            }
        }
    }
    if (g.oriented)
    {
        return c;
    }
    else
    {
        return c / 2;
    }
}

void write_graphe(char *filename, graph g)
{
    // crée un graphe aléatoire à nv sommets et ne arcs
    int nv = g.size;
    int ne = count_edges(g);
    int o;
    if (g.oriented)
    {
        o = 1;
    }
    else
    {
        o = 0;
    }
    FILE *writer = fopen(filename, "w");
    if (writer == NULL)
    {
        printf("Echec création du fichier %s !\n", filename);
        exit(EXIT_FAILURE);
    }
    fprintf(writer, "%d %d %d\n", nv, ne, o);
    for (int i = 0; i < nv; i++)
    {
        for (int j = 0; j < nv; j++)
        {
            if (g.mat[i * nv + j])
            {
                fprintf(writer, "%d %d\n", i, j);
            }
        }
    }
    fclose(writer);
}

graph random_graph(int nv, int ne, bool or)
{
    //Renvoie un graphe aléatoire de nv noeuds et ne arcs
    graph g = make_graphe(nv, or);
    int cpt = 0;
    int s,t;
    while (cpt!=ne)
    {
        s = rand()%nv;
        t = rand()%nv;
        if (s!=t && !g.mat[s*nv+t])
        {
            cpt += 1;
            make_edge(g, s, t);
        }
    }
    return g;
}

void visualize(graph g)
{
    int n = g.size;
    FILE *writer = fopen("temp.gv", "w");

    char c;
    int s;
    if (g.oriented)
    {
        c = '>';
        fprintf(writer, "digraph mygraph {\n");
    }
    else
    {
        c = '-';
        fprintf(writer, "graph mygraph {\n");
    }
    for (int i = 0; i < n; i++)
    {
        if (g.oriented)
        {
            s = 0;
        }
        else
        {
            s = i + 1;
        }
        for (int j = s; j < n; j++)
        {
            if (g.mat[i * n + j])
            {
                fprintf(writer, "%d -%c %d\n", i, c, j);
            }
        }
    }
    fprintf(writer, "}\n");
    fclose(writer);
    system("xdot temp.gv &");
}

void free_graph(graph g)
{
    free(g.mat);
}

int main()
{
    srand(time(NULL));
    graph g = random_graph(10,20,true);
    write_graphe("rg.txt",g);
    visualize(g);
    free_graph(g);
    return EXIT_SUCCESS;
}