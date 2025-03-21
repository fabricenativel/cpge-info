// Découpe de valeur maximale d'une barre
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void lire_barre(char *fname, int barre[], int size)
{
    FILE *reader = fopen(fname, "r");
    int p;
    for (int i = 0; i < size; i++)
    {
        fscanf(reader, "%d\n", &p);
        barre[i] = p;
    }
    fclose(reader);
}

// Découpe maximale d'une barre de taille n
int vmax(int barre[], int n) {
    int cmax = 0;
    int vnk;
    if (n == 0) {return 0;}
    for (int k = 1; k <= n; k++){
        vnk = vmax(barre, n-k);
        if (barre[k] + vnk > cmax) {cmax = vnk + barre[k];}
        }
    return cmax;}

// Avec mémoisation (v[n]=-1 indique une valeur non encore calculée)
int vmax_memo(int barre[], int n, int v[]){
    if (v[n]!=-1) {return v[n];}
    int cmax = 0;
    int vnk;
    for (int k = 1; k <= n; k++){
        vnk = vmax_memo(barre, n-k, v);
        if (barre[k] + vnk > cmax) {cmax = vnk + barre[k];}
        }
    v[n] = cmax;
    return cmax;}


int vmax_iter(int barre[], int n){
    int vmax[n];
    vmax[0] = 0;
    vmax[1] = barre[1];
    for (int i=2; i<=n; i++){
        vmax[i] = 0;
        for (int j=1; j<=i; j++){
            if (vmax[j]+barre[i-j]>vmax[i])
            {vmax[i] = vmax[j]+barre[i-j];}}}
    return vmax[n];}
    

int main()
{
    int bsize = 12;
    int barre[bsize+1];
    int v[bsize+1];
    float st,et;
    int res;
    for (int k=0;k<bsize+1;k++)
    {
        v[k] = -1;
    }
    v[0] = 0;
    lire_barre("ex1.txt", barre, bsize+1);
    st = (float)clock() / CLOCKS_PER_SEC;
    res = vmax(barre, bsize);
    et = (float)clock() / CLOCKS_PER_SEC;
    printf("Solution = %d obtenue en %f s\n", res, et-st);
    st = (float)clock() / CLOCKS_PER_SEC;
    res = vmax_memo(barre, bsize, v);
    et = (float)clock() / CLOCKS_PER_SEC;
    printf("Solution (mémo) = %d obtenue en %f s\n", res, et-st);
    st = (float)clock() / CLOCKS_PER_SEC;
    res = vmax_iter(barre, bsize);
    et = (float)clock() / CLOCKS_PER_SEC;
    printf("Solution (itérative) = %d obtenue en %f s\n", res, et-st);

}
