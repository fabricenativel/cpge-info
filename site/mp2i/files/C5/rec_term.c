#include <stdio.h>
#include <stdlib.h>

int mult(int a, int b)
{
    if (b==0)
    {return 0;}
    return a + mult(a,b-1);
}

int mult_acc(int a, int b, int acc)
{
    if (b==0)
    {return acc;}
    return mult_acc(a, b-1, acc+a);
}

int main(int argc, char* argv[])
{
    if (argc!=3)
    {
        printf("Donner a et b en ligne de commande \n");
    }
    else
    {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        printf("%d \n",mult_acc(a,b,0));
    }
}