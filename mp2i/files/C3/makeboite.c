#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fichier = fopen("boites.txt","w");
    char code[4];
    int longueur,largeur,hauteur;
    for (int i=0;i<1000;i++)
    {
        for (int j=0;j<4;j++)
        {
            code[j] = 65+rand()%26;
        }
        longueur = rand()%200+90;
        largeur = rand()%30+50;
        hauteur = rand()%80+ 20;
        fprintf(fichier,"%c%c%c%c %d %d %d \n",code[0],code[1],code[2],code[3],longueur,largeur,hauteur);
    }
    fclose(fichier);
}

