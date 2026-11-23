#include <stdio.h>
#include <stdint.h>
int main()
{
    uint64_t s = 0;
    for (uint64_t i=0;i<100000000;i++)
    {
        s = s + i;
    }
    printf("s = %ld\n",s);
}