#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NMAX  100 // nombre maximal de sommets
// graphe[i][0] contient le nombre de sommets adjacents 
// graphe[i][1..] est la liste d'adjacence du sommet i
typedef int graphe[NMAX][NMAX];


void init_graphe(graphe g, int size)
{
    for (int i = 0; i < size; i++)
            g[i][0] = 0;
}

void cree_arete(graphe g, int i, int j){
    g[i][0]++;
    g[j][0]++;
    g[i][g[i][0]] = j;
    g[j][g[j][0]] = i;}

void affiche_graphe(graphe g, int size)
{
    for (int i=0; i<size;i++)
    {
        printf("%d --> [",i);
        for (int j=1;j<=g[i][0];j++)
        {   
            printf("%d",g[i][j]);
            if (j!=g[i][0]) {printf(", ");}
        }
        printf("]\n");
    }
}

void visualise(graphe g, int n)
{
    char buf[256];
    FILE *writer = fopen("temp.gv", "w");
    FILE *imgwriter = fopen("temp.jpg", "wb");
    fprintf(writer, "graph mygraph {\n");
    for (int i=0; i<n; i++)
    {
        for (int j=1; j<=g[i][0]; j++)
        {
                if (i>g[i][j]) {fprintf(writer,"%d -- %d\n",i,g[i][j]);}
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


int main()
{
    graphe g;
    init_graphe(g, 5);
    cree_arete(g, 1, 3);
    cree_arete(g, 2, 4);
    cree_arete(g, 0, 1);
    cree_arete(g, 0, 2);
    cree_arete(g, 0, 3);
    affiche_graphe(g, 5);
    visualise(g,5);
}