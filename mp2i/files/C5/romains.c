#include <stdio.h>
#include <string.h>

int valeur_chiffre(char c)
{
    switch(c)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
}

int valeur_nombre(char romains[])
{
    if (strlen(romains)==1)
    {
        return valeur_chiffre(romains[0]);
    }
    if (valeur_chiffre(romains[0])>=valeur_chiffre(romains[1]))
    {
        return valeur_chiffre(romains[0])+valeur_nombre(&romains[1]);
    }
    else
    {
        return -valeur_chiffre(romains[0])+valeur_nombre(&romains[1]);
    }

}
int main(int argc, char* argv[])
{
    for (int i=1;i<argc;i++)
    {
        printf("%s = %d\n",argv[i],valeur_nombre(argv[i]));
    }
}
