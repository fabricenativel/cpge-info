#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char chiffre_car(char car, int cle)
{
    cle = (cle % 26);
    if (cle < 0)
    {
        cle = cle + 26;
    }
    if ('A' <= car && car <= 'Z')
    {
        return 'A' + ((car - 'A') + cle) % 26;
    }
    if ('a' <= car && car <= 'z')
    {
        return 'a' + ((car - 'a') + cle) % 26;
    }
    return car;
}

char *chiffre_chaine(char chaine[], int cle)
{
    int size = strlen(chaine);
    char *resultat = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size; i++)
    {
        resultat[i] = chiffre_car(chaine[i], cle);
    }
    resultat[size] = '\0';
    return resultat;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Il faut donner en argument une chaine de caractères et une clé de chiffrement\n");
    }
    else
    {
        char *res;
        res = chiffre_chaine(argv[1], atoi(argv[2]));
        printf("%s\n", res);
        free(res);
    }
}
