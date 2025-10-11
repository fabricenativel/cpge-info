#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *bruteforce(char *mdp, char *charset, int size)
{
    char *test = malloc(sizeof(char) * size);
    int nb_char = strlen(charset);
    int idx[size];
    int cidx;
    for (int k = 0; k < size; k++)
    {
        idx[k] = 0;
        test[k] = charset[0];
    }
    while (idx[0] < nb_char)
    {
        if (strcmp(test, mdp) == 0)
        {
            return test;
        }
        idx[size - 1]++;
        cidx = size - 1;
        while (cidx != 0 && idx[cidx] == nb_char)
        {
            idx[cidx] = 0;
            test[cidx] = charset[0];
            cidx--;
            idx[cidx]++;
            test[cidx] = charset[idx[cidx]];
        }
        test[size - 1] = charset[idx[size - 1]];
    }
    return "";
}

int main()
{
    char charset[26];
    for (int i = 0; i < 26; i++)
    {
        charset[i] = 97 + i;
    }
    int size = 8;
    char mdp[] = "terrible";
    char *bf = bruteforce(mdp, charset, size);
    printf("Mot de passe trouvé : %s\n", bf);
}