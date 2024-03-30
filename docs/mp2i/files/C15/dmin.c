#include <stdio.h>
#include <stdbool.h>
#include <math.h>
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
    if (b<c) {return c;}
    return a;
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
    // Cas de base
    if (fin-deb==2) {return distance(nuage[deb],nuage[deb+1]);}
    if (fin-deb==3) {return min3((distance(nuage[deb],nuage[deb+1]),distance(nuage[deb],nuage[deb+2]),distance(nuage[deb+1],nuage[deb+2])));}
    // Diviser
    int mid = (fin+deb)/2;
    // Régner
    dg = dmin_dpr(nuage, deb, mid);
    dd = dmin_dpr(nuage, mid, fin);
    if (dg<dd) {dm=dg;} else {dm=dd;}
    // Combiner
    

}

int main()
{
    int t = 1000;
    point *nuagex = lire_points("nuage.txt",t);
    qsort(nuagex, nb, sizeof(point), cmpx);
    point *nuagey = malloc(sizeof(point)*t);
    qsort(nuagey, nb, sizeof(point), cmpy);
    for (int i=0;i<10;i++)
    {
        printf("(%lf,%lf)\n",nuage[i].x,nuage[i].y);
    }
    double dm = dmin(nuage, t);
    printf("Distance minimale = %lf\n",dm);
    free(nuagex);
    free(nuagey);
}