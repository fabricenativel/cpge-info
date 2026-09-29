#include <stdio.h>
#include <stdint.h>

// Compte à rebours de n à 0
void compte_rebours(int n)
{
    while (n != 0)
    {
        printf("%d \n",n);
        n = n-1;
    }
    printf("Partez !\n");
}

int main()
{
    compte_rebours(10);
}
