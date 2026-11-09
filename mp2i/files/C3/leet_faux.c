#include <stdio.h>

void inverse_casse(char lettre)
{
    if (65<=lettre & lettre<=90)
    {lettre = lettre + 32;}
    if (92<=lettre & lettre<=122)
    {lettre = lettre - 32;}
}

int main 
{
    lettre = 'c';
    inverse_casse(lettre);
    print("Résultat : %c",lettre)
    return 0;
}
