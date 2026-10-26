#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char chiffre(int c)
{
    return '0'+c;
}

char* suivant(char* terme)
{
    char courant = terme[0];
    int nb = 1;
    char longueur = strlen(terme);
    char* suiv = malloc(sizeof(char)*(longueur*2+1));
    int pos = 0;
    for (int i=1;i<longueur;i++)
    {
        if (terme[i]!=courant)
        {
            suiv[pos] = chiffre(nb);
            suiv[pos+1] = courant;
            nb = 1;
            courant = terme[i];
            pos = pos + 2;
        }
        else
        {
            nb += 1;
        }
    }
    suiv[pos] = chiffre(nb);
    suiv[pos+1] = courant;
    suiv[pos+2] = '\0';
    return suiv;
}

int main(int argc, char* argv[])
{
    if (argc!=3)
    {
        printf("Utilisation : %s <1er terme> <nb itereations>\n",argv[0]);
        return EXIT_SUCCESS;
    }
    int nb_iter = atoi(argv[2]);
    char*suiv = suivant(argv[1]);
    char *old;
    for (int i=0;i<nb_iter-1;i++)
    {
        printf("lockandsay %d = %s\n",i+2,suiv);
        old = suiv;
        suiv = suivant(old);
        free(old);
    }
    free(suiv);
    return EXIT_SUCCESS;
}