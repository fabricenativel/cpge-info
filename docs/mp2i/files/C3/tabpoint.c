#include <stdio.h>

void f()
{
    int t[5];
    printf("Dans la fonction : \n");
    printf("%p \n",t);
    printf("%p \n",&t);
}

int main()
{
    int t[5];
    printf("Dans le main : \n");
    printf("%p \n",t);
    printf("%p \n",&t);
    f(t);
}