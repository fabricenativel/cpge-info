#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define LARGEUR 100
#define HAUTEUR 100
#define TAILLE HAUTEUR*LARGEUR




bool rand_bool()
{
    if (rand()%2==0) return true; else return false;

}

int main()
{
    srand(time(NULL));
    bool *etat = malloc(sizeof(bool)*TAILLE);
    int viv = 0;
    for (int i=0;i<HAUTEUR;i++)
    {
        for (int j=0;j<LARGEUR;j++)
        {       
            etat[i*LARGEUR+j] = rand_bool();
        }
    }
    FILE * writer = fopen("grille100x100.txt","w");
    for (int i=0;i<HAUTEUR;i++)
    {
        for (int j=0;j<LARGEUR;j++)
        {   
            if (etat[i*LARGEUR+j])
            { fprintf(writer,"%c",'1');
             viv += 1;
             }
            else
            { fprintf(writer,"%c",'0');}
        }
        fprintf(writer,"%c",'\n');
    }
    fclose(writer);
    printf("Fichier crée, il contient %d cellules vivantes\n",viv);
}