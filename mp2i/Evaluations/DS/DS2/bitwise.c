#include <stdint.h>
#include <stdio.h>

int main()
{
    uint8_t x = 5;
    printf("%hhu\n",~x);
    printf("%hhu\n",42 & 57);
    printf("%hhu\n",42 | 57);
    printf("%hhu\n",42 >> 3);
}
    
