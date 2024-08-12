
/******************************************************/
/* Concours commun INP                                */
/* https://www.concours-commun-inp.fr                 */
/* CC BY-NC-SA, Novembre 2023                         */
/* https://creativecommons.org/licenses/by-nc-sa/4.0/ */
/******************************************************/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct nb{
    double x;
    struct nb* suivant;
};

//Question 2
int epsilon(){
    //A compléter
}

//Question 3
double u(int n){
    //A compléter
}

//Question 5
double somme(struct nb* tab){
    //A compléter
}

double somme2(struct nb* tab){
    //on suppose que tab est triée par ordre
    //croissant et est non vide

    struct nb* temp=tab;

    while(temp!=NULL) {
        if (temp->suivant !=NULL) {
            struct nb* s;
            //Création du maillon s contenant la somme des 2 premiers éléments
            // A compléter
            //temp pointe vers le 3e élément de la liste
            temp=(temp->suivant)->suivant;
            //recherche de l'emplacement de s

            struct nb* t=temp;
            struct nb* t2=temp;

            while(t!=NULL){
                /*si la valeur pointée par t
                est supérieure strictement à celle de s,
                t pointe sur l'élément suivant
                sinon on quitte la boucle
                */
                //A compléter
            }
            //insertion de s
            if (t==NULL & t2==NULL) {
                temp=s;
            } else {
                if (t==NULL & t2!=NULL){
                    t2->suivant=s;
                } else {
                    t2->suivant=s;
                    s->suivant=t;
                }
            }
        } else {
            return temp->x;
        }
    }
    return temp->x;
}

int main(){
    double a=2e65;
    double b=-2e65;
    double c=1.0;
    printf("\n Question 1\n");
    //Calcul et affichage de (a+b)+c et a+(b+c)
    //A compléter
    // printf("\n epsilon machine %i\n",epsilon());

    printf("\n Question 4\n");
    //Affichage des 22 premiers termes
    // A compléter

    printf("\n Question 5-6\n");
    //Test des sommes
    struct nb* l = malloc(sizeof(struct nb));

    l->x=1./(pow(10,5));
    l->suivant=NULL;

    struct nb* temp=l;

    for(int i=pow(10,5)-1;i>0;i=i-1) {
         struct nb* n=malloc(sizeof(struct nb));
         n->x=1./(float)i;
         n->suivant=NULL;
         temp->suivant=n;
         temp=temp->suivant;
     }

     //printf("\n somme  %.15lf\n" ,somme(l));
    // printf("\n somme  %.15lf\n ",somme2(l));

    return 0;
}
