#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char chiffre_car(char car,int cle)
{
    return 65+((car-65)+cle)%26;
}

char* chiffre_chaine(char chaine[], int cle)
{
    int size = strlen(chaine);
    char * resultat = malloc(sizeof(char)*(size+1));
    for (int i=0;i<size;i++)
    {
        resultat[i] = chiffre_car(chaine[i], cle);
    }
    resultat[size] = '\0';
    return resultat;
}

int main()
{
    char * res;
    res  = chiffre_chaine("NSI",14);
    printf("%s\n",res);
    free(res);
}


