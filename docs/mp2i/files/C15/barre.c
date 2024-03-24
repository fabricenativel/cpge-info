// Découpe de valeur maximale d'une barre
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
    int vk;
    if (n == 0) {return 0;}
    for (int k = 0; k < n; k++){
        vk = vmax(barre, k);
        if (barre[n-k] + vk > cmax) {cmax = vk + barre[n-k];}
        }
    return cmax;}

// Avec mémoisation (v[n]=-1 indique une valeur non encore calculée)
int vmax_memo(int barre[], int n, int v[]){
    if (v[n]!=-1) {return v[n];}
    int cmax = 0;
    int vk;
    for (int k = 0; k < n; k++){
        vk = vmax_memo(barre, k, v);
        if (barre[n-k] + vk > cmax) {cmax = vk + barre[n-k];}
        }
    v[n] = cmax;
    return cmax;}

int main()
{
    int bsize = 13;
    int barre[bsize];
    int v[bsize];
    for (int k=0;k<bsize;k++)
    {
        v[k] = -1;
    }
    v[0] = 0;
    lire_barre("ex1.txt", barre, bsize);
    printf("Solution = %d \n", vmax(barre, 12));
    printf("Solution (mémo) = %d \n", vmax_memo(barre, 12, v));

}
