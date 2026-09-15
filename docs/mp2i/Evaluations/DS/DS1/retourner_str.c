#include <stdio.h>
#include <stdbool.h>

void echange(char s[], int i, int j)
{
    // echange les caractères situés aux indices i et j dans s
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void retourner_str(char s[])
{
    // Retourne en place la chaine de caractère s
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    int i = 0;
    int j = n - 1;
    while (j - i > 0)
    {
        echange(s, i, j);
        i = i + 1;
        j = j - 1;
    }
}

bool palindrome(char s[])
{
    //renvoie true ssi s est un palindrome
    char copie[] = s;
    retourner_str(copie);
    return s==copie;
}

int main()
{
    char test[] = "Ok, tout va bien !";
    retourner_str(test);
    printf("%s \n", test);
}