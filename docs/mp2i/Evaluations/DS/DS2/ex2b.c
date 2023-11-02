#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

bool appartient(uint64_t s, int e)
{
    return s>>e & 1 == 1;
}

int main()
{
    for (int i=0;i<10;i++)
    {
        if (appartient(34,i)) printf("%d est dans \n",i); else printf("%d pas dans\n",i);
    }
}