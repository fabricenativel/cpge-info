#include <stdio.h>

int main(){
    FILE *fichier = fopen("entiers.txt","r");
    int n, somme = 0;
    while (fscanf(fichier,"%d",&n)!=EOF) {
        somme = somme + n;}
    fclose(fichier);
    printf("Somme = %d\n",somme);
    return 0;}