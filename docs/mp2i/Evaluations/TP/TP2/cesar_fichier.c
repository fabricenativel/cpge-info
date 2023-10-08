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
        printf("Il faut donner en argument un nom de fichier et une clé de chiffrement\n");
    }
    else
    {
        char *res, car;
        char *data = malloc(sizeof(char) * 255);
        FILE *lecteur = fopen(argv[1], "r");
        int nb_char = 0;
        while (nb_char < 255 && (car = fgetc(lecteur)) != EOF)
        {
            data[nb_char] = car;
            nb_char++;
        }
        data[nb_char] = '\0';
        fclose(lecteur);
        res = chiffre_chaine(data, atoi(argv[2]));
        printf("%s\n", res);
        free(res);
        free(data);
    }
}
