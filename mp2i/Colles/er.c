#include <stdio.h>
#include <stdint.h>


uint32_t exprap(uint32_t a, unsigned n)
{
    uint32_t r = 1;
    uint32_t  k = a;
    unsigned  p = n;
    while (p != 0)
    {
        if (p % 2 == 1)
        {
            r = r * k;
        }
        k = k *k;
        p = p / 2;
    }
    return r;
}

int main()
{
    printf("2**32 = %u\n",exprap(2,32));
}