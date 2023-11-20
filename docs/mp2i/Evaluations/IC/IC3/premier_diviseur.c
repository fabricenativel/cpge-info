#include <stdlib.h>
#include <stdio.h>


// Renvoie le premier diviseur > 1 de l'entier n(>=2)
int premier_diviseur(int n){
    int candidat = 2;
    while (n%candidat !=0) {
        candidat = candidat+1;}
    return candidat;}

int main(int argc, char *argv[])
{
    int n  = atoi(argv[1]);
    printf("Premier diviseur de %d = %d\n", n, premier_diviseur(n));
}