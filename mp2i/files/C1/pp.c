#include <stdio.h>

int main()
{
    int s = 0;
    int f = 1;
    for (int i=1;i<=2024;i++)
    {
        if (i%7==0 && i%13==0)
        { s += i;}
    }
    printf("Résultat = %d\n",s);
    for (int i=1;i<=13;i++)
    {
        f = f *i;
    }
    printf("Factorielle = %d\n",f);

}