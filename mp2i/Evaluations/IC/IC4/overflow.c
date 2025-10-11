#include <stdio.h>
#include <stdint.h>

int main()
{
    for (uint8_t i = 10; i >= 0; i--)
    { // %u est le spécificateur de format des entiers non signés
        printf("%u\n", i);
    }
    printf("Partez !\n");
}