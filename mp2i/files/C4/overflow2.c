#include <stdio.h>
#include <stdint.h>

int main()
{
    uint8_t n1 = 240; // 8 bits donc valeur maximale 255
    uint32_t n2 = 0; // valeur minimale 0 (non signé)
    n1 = n1 + 20; // overflow : 260 
    n2 = n2 - 1; // underflow : -1
    printf("valeur de n1 = %u\n",n1); // 4 (car 260 = 4 modulo 256)
    printf("valeur de n2 = %u\n",n2); // 4294967295 (car -1 = 4294967295 modulo 4294967296)
 }