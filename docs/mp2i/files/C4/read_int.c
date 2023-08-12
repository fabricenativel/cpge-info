#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

/* Norme IEEE-754 simple précision = type float*/
#define MANTISSE 23
#define EXPOSANT 8
#define SIGNE 1
#define SIZE  32

uint8_t* get_bits(uint32_t n)
{
    uint8_t* bits = malloc(sizeof(uint8_t)*SIZE);
    for (int i=0;i<32;i++)
    {
        bits[i]=n%2;
        n=n/2;
    }
    return bits;
}

void print_bits(uint8_t bits[])
{
    for (int i=0;i<SIZE;i++)
    {
        printf("%d",bits[i]);
    }
    printf("\n");
}

int main(int argc,char* argv[])
{
    assert (argc==2);
    uint32_t ntest = (uint32_t)atoi((argv[1]));
    print_bits(get_bits(ntest));
}

