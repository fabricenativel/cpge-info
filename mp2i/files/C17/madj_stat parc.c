#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NMAX 100 // nombre maximal de sommets
typedef bool graphe[NMAX][NMAX]; // La matrice d'adjacence

void init_graphe(graphe g, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            g[i][j] = false;
        }
    }
}

void cree_arete(graphe g, int i, int j){
    g[i][j] = true;
    g[j][i] = true;}

void affiche_graphe(graphe g, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (g[i][j])
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

// Visualisation du graphe g de taille n
void visualise(graphe g, int n)
{
    char buf[256];
    FILE *writer = fopen("temp.gv", "w");
    FILE *imgwriter = fopen("temp.jpg", "wb");
    fprintf(writer, "graph mygraph {\n");
    for (int i=0; i<n; i++)
    {
        fprintf(writer,"%d\n",i);
        for (int j=i+1; j<n; j++)
        {
            if (g[i][j])
            {
                fprintf(writer,"%d -- %d\n",i,j);
            }
        }
    }
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


void complet(graphe g, int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n+1;j++)
        {

            cree_arete(g,i,j);
        }
    }
}

int main()
{
    graphe g;
    complet(g,5);
    visualise(g,5);
}