#include <stdio.h>
#include <stdbool.h>

int longueur(char s[])
{
    int l = 0;
    while (s[l]!='\0')
    {
        l++;
    }
    return l;
}

bool palindrome_iter(char s[])
{
    int l = longueur(s);
    for (int i=0;i<l/2;i++)
    {
        if (s[i]!=s[l-i-1]) return false;
    }
    return true;
}

bool palindrome_rec(char s[],int deb, int fin)
{
    if ((fin-deb)<2)
    {
        return true;
    }
    else
    return s[deb]==s[fin] && palindrome_rec(s,deb+1,fin-1);
}

int main(int argc, char *argv[])
{
    if (argc!=2) 
    {printf("Entrer une chaine de caractères \n");}
    else
    {
        if (palindrome_rec(argv[1],0,longueur(argv[1])-1))
        {
            printf("est un palindrome \n");
        }
        else
        {
            printf("n'est pas un palindrome \n");
        }
    }
}