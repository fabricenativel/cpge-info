#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

/* Norme IEEE-754 simple précision = type float*/
#define MANTISSE 23
#define EXPOSANT 8
#define SIGNE 1
#define SIZE  32
#define BIAIS 127

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
    int exp = 0;
    float mantisse = 0.0;
    int poids = 128;
    float poids_mant = 2.0;
    float s;
    float check;
    printf("> Signe : %d = ",bits[SIZE-1]);
    if (bits[SIZE-1]==0) 
    {
        printf("+\n");
        s = 1.0;
    }
    else
    {
        printf("-\n");
        s = -1.0;
    }
    printf("> Exposant : ");
    for (int i=SIZE-2;i>SIZE-2-EXPOSANT;i--)
    {
        printf("%d",bits[i]);
        exp += bits[i]*poids;
        poids = poids / 2;
    }
    exp = exp-BIAIS;
    printf(" = %d\n",exp);
    printf("> Mantisse : ");
    for (int i=SIZE-2-EXPOSANT;i>=0;i--)
    {
        printf("%d",bits[i]);
        mantisse = mantisse + bits[i]/poids_mant;
        poids_mant = poids_mant*2;
    }
    printf(" = %f\n",mantisse);
    check = s * (mantisse+1) * pow(2.0,exp);
    printf("Vérification : %f\n",check);

}

int main(int argc,char* argv[])
{
    assert (argc==2);
    float ftest = (float)atof((argv[1]));
    uint32_t* ntest = &ftest; 
    print_bits(get_bits(*ntest));
}

