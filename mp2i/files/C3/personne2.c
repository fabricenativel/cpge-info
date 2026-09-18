#include <stdio.h>

struct personne_struct{
    char nom[50];
    float taille;
    float poids;};
typedef  struct personne_struct personne;

void change_poids(personne *p, float modification){
    p->poids = p->poids + modification;}

int main(){
    personne hulk = {.nom = "Hulk",.poids=650,.taille=2.50};
    change_poids(&hulk,-100.0);
    printf("Le poids de %s est  : %f\n",hulk.nom,hulk.poids);
    return 0;}