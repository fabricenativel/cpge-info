// Découpe de valeur maximale d'une barre

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct morceau
{ 
    int taille;
    int prix;
};
typedef struct morceau morceau;


void lire_barre(char * fname, morceau barre[], int size)
{
    FILE * reader = fopen(fname,"r");
    int  p;
    int t;
    for (int i=0; i<size; i++)
    {
        fscanf(reader,"%d,%d\n",&t,&p);
        barre[i].taille = t ;
        barre[i].prix = p;
    }
    fclose(reader);
}

int vmax(morceau barre[], int bsize, int size, int calcule[])
{
        if (calcule[size]!=-1) {return calcule[size];}
        else
        {
            int cmax = 0;
            int vi;
            for (int i=0; i<bsize; i++)
            {
                if (barre[i].taille <= size)
                {
                    vi = vmax(barre, bsize, size-barre[i].taille, calcule);
                    calcule[size-barre[i].taille] = vi;
                    if (barre[i].prix +  vi > cmax) {cmax = vi + barre[i].prix;}
                }
            }
            return cmax;
        }    
}

int main()
{
    morceau barre[12];
    int lmax = 120;
    int calc[lmax+1];
    for (int i=1; i<lmax+1; i++) {calc[i]=-1;}
    calc[0] = 0;
    lire_barre("ex1.txt",barre,12);
    printf("Solution = %d \n", vmax(barre, 12, lmax, calc));
}
