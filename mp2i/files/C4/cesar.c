#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool est_majuscule(char c)
{
    return ('A' < c && c < 'Z');
}

char cesar_lettre(char c, int d)
{
    if (est_majuscule (c))
    {
        int num = c - 'A';
        num = (num + d) % 26;
        return 'A' + num;
    }
    else
    {
        return c;
    }
}

char *cesar_texte(char *c, int d)
{
    int n = strlen(c);
    char *res = malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++)
    {
        res[i] = cesar_lettre(c[i], d);
    }
    res[n] = '\0';
    return res;
}

int main()
{
    char *test = cesar_texte("BIENVENUE EN CPGE !", 9);
    printf("%s \n", test);
    free(test);
    return 0;
}
