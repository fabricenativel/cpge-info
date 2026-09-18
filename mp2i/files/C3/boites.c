#include <stdio.h>
#include <stdlib.h>


#define FILE_SIZE 1000


struct boite
{   char  *reference;
    int longueur;
    int largeur;
    int hauteur;
};
typedef struct boite boite;

int volume(boite b)
{
    return b.longueur*b.largeur*b.hauteur;
}

int main()
{
    FILE* reader=fopen("boites.txt","r");
    boite boites[1000];
    int vmax = 0;
    char *refmax;
    for (int i=0; i<1000; i++)
    {   
        boites[i].reference = malloc(sizeof(char)*4);
        fscanf(reader,"%s %d %d %d\n",boites[i].reference,&boites[i].longueur, &boites[i].largeur,&boites[i].hauteur);
    }
    for (int i=0; i<1000; i++)
    {
        if (volume(boites[i])>vmax)
        {
            vmax = volume(boites[i]);
            refmax = boites[i].reference;
        }
    }
    printf("La boîte de plus grand volume est %s avec un volume de %d\n",refmax,vmax);

}