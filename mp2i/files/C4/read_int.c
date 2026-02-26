#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <assert.h>

/* Norme IEEE-754 simple précision = type float*/
#define MANTISSE 23
#define EXPOSANT 8
#define SIGNE 1
#define SIZE  32
#define BIAIS 127

//Lecture des bits d'un entier  signé représenté sur size octets
uint8_t* get_bits(uint64_t n, int size)
{   assert (size<32);
    uint8_t* bits = malloc(sizeof(uint8_t)*size);
    for (int i=0;i<size;i++)
    {
        bits[size-i-1]=(n >> i) & 1;
    }
    return bits;
}


void bits_uint(uint8_t bits[], int size)
{
    for (int i=0;i<size;i++)
    {
        printf("%u",bits[i]);
    }
}


int main(int argc,char* argv[])
{
    int bnumber = atoi(argv[2]);
    uint8_t *bits = get_bits(atoi(argv[1]),bnumber);
    bits_uint(bits,bnumber);
    printf("\n");
    free(bits);
}

