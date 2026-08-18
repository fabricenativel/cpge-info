#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>

char* binaire(uint8_t n)
{
    char* bin = malloc(sizeof(uint8_t)*8);
    for (int i=0;i<8;i++) 
    {
        if (n%2==0)
        {bin[7-i]=0;}
        else
        {bin[7-i]=1;}
        n = n/2;
    }
    return bin;
}

int main(int argc,char *argv[])
{
    assert (argc==2);
    char* rep = binaire(atoi(argv[1]));
    //printf("%s\n",rep);
    for (int i=0;i<8;i++)
    {
        printf("%d",rep[i]);
    }
    printf("\n");
    free(rep);
}