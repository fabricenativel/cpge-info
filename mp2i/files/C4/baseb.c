#include <stdio.h>
#include <stdlib.h>

const char* CHIFFRES="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int nb_chiffres(int n, int b)
{
    
    int p = 0;;
    if (n==0)
    {
        return 1;
    }
    while (n!=0)
    {
        p+=1;
        n=n/b;
    }
    return p;
}


char* chiffres(int n, int b)
{
    int p = nb_chiffres(n,b);
    char * chiffres = malloc(sizeof(char)*(p+1));
    if (n==0)
    {
        chiffres[0]='0';
    }
    for (int i=0;i<p;i++)
    {
        chiffres[p-1-i] = CHIFFRES[n%b];
        n =n/b;
    }
    chiffres[p]='\0';
    return chiffres;
}

int main(int argc, char* argv[])
{
    if (argc!=3) {printf("Utilisation : baseb <nombre> <base> \n");}
    else
    {int n=atoi(argv[1]);
    int b=atoi(argv[2]);
    char *res = chiffres(n,b);
    printf("Résultat : %s\n",res);
    free(res);}
    return 0;
}