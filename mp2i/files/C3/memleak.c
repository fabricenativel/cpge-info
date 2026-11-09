#include <stdio.h>
#include <stdlib.h>

int memleak(int a){
    int* b = malloc(sizeof(int)); //b pointe vers le tas
    *b = a*a; 
    return *b; //on renvoie la VALEUR de b
} //L'adresse de b est dépilée donc perdue

int main(){
    int x = 42;
    int y = memleak(x); //y récupère la valeur de b
    printf("Valeur de y = %d\n", y);
}// On n'a pas de référence vers b, on ne peut pas free