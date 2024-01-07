#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct salle {
    char batiment;
    int numero;
    int capacite;
    bool ordinateur;
};
typedef struct salle salle;

salle cree_salle(char b, int n, int c, bool o)
{
    salle s = {.batiment = b, .numero = n, .capacite = c, .ordinateur = o};
    return s;
}

void modifie_capacite(salle* s, int nc)
{
    s->capacite = nc;
}

void affiche_salle(salle s)
{
    printf("Salle %c%d de capacité %d ",s.batiment,s.numero,s.capacite);
    if (s.ordinateur) {printf("(Salle informatique)");}
    printf("\n");
}

int capacite_batiment(salle* salles, int size, char bat)
{
    int capa_bat = 0;
    for (int i=0; i<size;i++)
    {
        if (salles[i].batiment==bat) 
        {
            capa_bat += salles[i].capacite;
        }
    }
    return capa_bat;
}

salle* lire_salle()
{
    FILE* lecteur = fopen("salles.txt","r");
    salle *salles = malloc(sizeof(salle)*100);
    int info;
    char bat;
    int num, capa;
    for (int i=0;i<100;i++)
    {
        fscanf(lecteur,"%c%d %d %d\n",&bat,&num,&capa,&info);
        salles[i].batiment = bat;
        salles[i].numero = num;
        salles[i].capacite = capa;
        salles[i].ordinateur = (info == 1);
    }
    fclose(lecteur);
    return salles;
}

int main()
{ 
    salle *s;
    s = lire_salle();
    affiche_salle(s[0]);
    affiche_salle(s[1]);
    printf("Capacité batiment S = %d\n",capacite_batiment(s,2,'S'));
    free(s);
}