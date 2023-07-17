#include <stdio.h>
#include <stdint.h>

int main()
{
    uint8_t n1 = 240;
    uint32_t n2 = 0;
    n1 = n1 + 20;
    n2 = n2 - 1;
    printf("valeur de n1 = %u\n",n1);
    printf("valeur de n2 = %u\n",n2);
}