#include <stdio.h>
#include <stdlib.h>

int consecutifs_egaux(int nb_lancers) {
    int* lancers = malloc(sizeof(int)*nb_lancers);
    int cpt = 0;
    for (int i=0;i<nb_lancers;i++) lancers[i] = rand()%6+1;
    for (int i=0;i<nb_lancers-1;i++) {
        if (lancers[i]==lancers[i+1]) cpt++;}
    return cpt;}

int main() {
    int n = consecutifs_egaux(1000);
    printf("Nombre lancers consécutifs égaux : %d\n",n);
    return 0;}