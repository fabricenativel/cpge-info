#include <stdio.h>
#include <stdlib.h>

void do_nop(int n)
{
    int s;
    printf("Exécution de %d opérations\n",n);
    for (int i=0;i<n;i++)
    {
        s = i*3;
    }
}

int main(int argc, char* argv[])
{
    if (argc!=2)
    { printf("Entrer le nombre d'opérations\n");}
    else
    {do_nop(atoi(argv[1]));}
}