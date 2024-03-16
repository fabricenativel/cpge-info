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

int vmax(morceau barre[], int bsize, int size)
{
        if (size==0) {return 0;}
        else
        {
            int cmax = 0;
            int vi;
            for (int i=0; i<bsize; i++)
            {
                if (barre[i].taille <= size)
                {
                    vi = vmax(barre, bsize, size-barre[i].taille);
                    if (barre[i].prix +  vi > cmax) {cmax = vi + barre[i].prix;}
                }
            }
            return cmax;
        }    
}

int main()
{
    morceau barre[12];
    lire_barre("ex1.txt",barre,12);
    printf("Solution = %d \n", vmax(barre, 12, 24));
}
