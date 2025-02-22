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
{   assert (size<=32);
    uint8_t* bits = malloc((int)sizeof(uint8_t)*size);
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

void bits_float(uint8_t bits[])
{
    int exp = 0;
    float mantisse = 0.0;
    int poids = 128;
    float poids_mant = 0.5;
    float s;
    float check;
    printf("> Signe : \t %d = ",bits[0]);
    if (bits[0]==0) 
    {
        printf("+\n");
        s = 1.0;
    }
    else
    {
        printf("-\n");
        s = -1.0;
    }
    printf("> Exposant :\t ");
    for (int i=1;i<1+EXPOSANT;i++)
    {
        printf("%d",bits[i]);
        exp += bits[i]*poids;
        poids = poids / 2;
    }
    exp = exp-BIAIS;
    printf(" = %d (donne %d en décalé)\n",exp+BIAIS,exp);
    printf("> Mantisse :\t ");
    for (int i=1+EXPOSANT;i<SIZE;i++)
    {
        printf("%d",bits[i]);
        mantisse = mantisse + bits[i]*poids_mant;
        poids_mant = poids_mant/2;
    }
    printf(" = %f\n",mantisse);
    check = s * (mantisse+1) * pow(2.0,exp);
    printf("Vérification : %f\n",check);

}

int main(int argc,char* argv[])
{
    float ftest = (float)atof(argv[1]);
    uint32_t* ntest = &ftest; 
    uint8_t *bits = get_bits(*ntest,SIZE);
    bits_float(bits);
    free(bits);
}

