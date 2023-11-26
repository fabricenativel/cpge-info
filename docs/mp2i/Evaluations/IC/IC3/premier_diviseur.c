#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int mystere(int n){
    assert (n>1);
    int candidat = 2;
    while (n%candidat !=0) {
        candidat = candidat+1;}
    return candidat;}

int main(int argc, char *argv[])
{
    int n  = atoi(argv[1]);
    printf("Premier diviseur de %d = %d\n", n, mystere(n));
}