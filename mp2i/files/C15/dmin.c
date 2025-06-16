#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

struct point {
    double x;
    double y;
};
typedef struct point point;

double distance(point a, point b)
{
    return sqrt(pow(a.y-b.y,2.0)+pow(a.x-b.x,2.0));
}

double min3(double a, double b, double c)
{
    if (a<b && a<c) {return a;}
    if (b<c) {return b;}
    return c;
}



double dmin(point pt[], int nb)
{
    double dm = INFINITY;
    for (int i=0; i<nb; i++)
    {
        for (int j=i+1; j<nb; j++)
        {
            if (distance(pt[i],pt[j])<dm)
            {
                dm = distance(pt[i],pt[j]);
            }
        }
    }
    return dm;
}


int cmpx(const void *m, const void *n)
{
    point *a = (point *)m;
    point *b = (point *)n;
    if (a->x<b->x) {return -1;}  
    if (a->x==b->x) {return 0;}
    return 1;  
}

int cmpy(const void *m, const void *n)
{
    point *a = (point *)m;
    point *b = (point *)n;
    if (a->y<b->y) {return -1;}  
    if (a->y==b->y) {return 0;}
    return 1;  
}

point* lire_points(char* filename, int nb)
{
    FILE* reader = fopen(filename,"r");
    point* nuage = malloc(sizeof(point)*nb);
    double x,y;
    for (int i=0; i<nb; i++)
    {
        fscanf(reader,"%lf,%lf\n",&x,&y);
        nuage[i].x = x;
        nuage[i].y = y;
    }
    fclose(reader);
    return nuage;
}


// Renvoie la distance minimale entre les points d'indice deb(inclus) à fin(non inclus)
double dmin_dpr(point nuagex[], point nuagey[], int deb, int fin)
{
    double dg, dd, dm;
    int nb_pts = fin-deb;
    point * bande = malloc(sizeof(point)*100);
    int nb_bande = 0;
    int jmax;
    // Cas de base
    if (nb_pts==2) {return distance(nuagex[deb],nuagex[deb+1]);}
    if (nb_pts==3) {return min3(distance(nuagex[deb],nuagex[deb+1]),distance(nuagex[deb],nuagex[deb+2]),distance(nuagex[deb+1],nuagex[deb+2]));}
    // Diviser
    int mid = (fin+deb)/2;
    double xmid = nuagex[mid].x;
    // Régner
    dg = dmin_dpr(nuagex, nuagey, deb, mid);
    dd = dmin_dpr(nuagex, nuagey, mid, fin);
    if (dg<dd) {dm=dg;} else {dm=dd;}
    // Combiner en examinant les points de la bande de largeur 2d centrée autour de x_mid
    // Filtrer Ny pour récupérer les points de la bande
    for (int i=0;i<100;i++)
    {
        if ( abs(nuagey[i].x - xmid) <= dm)
        {
            bande[nb_bande++] = nuagey[i];
        }
    }
    // Pour chaque point tester au plus les 7 suivants
    for (int i=0; i<nb_bande;i++)
    {
        if (i+8<nb_bande) {jmax = i+8;} else {jmax = nb_bande;} 
        for (int j=i+1;j<jmax;j++)
        {
            if (distance(bande[i],bande[j])<dm) { 
                dm = distance(bande[i], bande[j]);}
                
        }
    }
    return dm;
}

int main(int argc, char* argv[])
{
    int t = atoi(argv[1]);
    srand(time(NULL));
    point *nuagex = malloc(sizeof(point)*t);
    for (int i=0;i<t;i++)
    {
        nuagex[i].x = (double)(rand()%100000);
        nuagex[i].y = (double)(rand()%100000);

    }
    qsort(nuagex, t, sizeof(point), cmpx);
    point *nuagey = malloc(sizeof(point)*t);
    for (int i=0;i<t;i++)
    {
        nuagey[i] = nuagex[i];
    }
    qsort(nuagey, t, sizeof(point), cmpy);
    double dm = dmin(nuagex, t);
    printf("Distance minimale (quadratique)= %lf\n",dm);
    double dmdpr = dmin_dpr(nuagex,nuagey,0,t);
    printf("Distance minimale (dpr) = %lf\n",dmdpr);
    free(nuagex);
    free(nuagey);
}