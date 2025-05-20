#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct abrNoeud_s
{
    char* cle;
    int valeur;
    struct abrNoeud_s* fils_gauche;
    struct abrNoeud_s* fils_droit;
};
typedef struct abrNoeud_s abrNoeud;

char *copie_chaine(char *s)
{
    int l = 0;
    while (s[l] != '\0')
        {l++;}
    char *s2 = malloc((l + 1) * sizeof(char));
    for (int i=0;i<=l;i++)
        {s2[i] = s[i];}
    return s2;
}

abrNoeud* creer_noeud(char *cle, int valeur, abrNoeud* fg, abrNoeud* fd)
{
    abrNoeud* noeud = malloc(sizeof(abrNoeud));
    noeud->cle = copie_chaine(cle);
    noeud->valeur = valeur;
    noeud->fils_gauche = fg;
    noeud->fils_droit = fd;
    return noeud;
}


int abr_equilibre(abrNoeud ab)
{
    int h_g = hauteur(g->fils_gauche);
    int h_d = hauteur(g->fils_droit);
    return (h_g - h_d);
}

void write_edge(FILE *writer, abrNoeud g, int *ninv)
{
    if (g.fils_gauche != NULL)
    {
        fprintf(writer, "\"(%s,%d)\"", g.cle,g.valeur);
        fprintf(writer, " -> ");
        fprintf(writer, "\"(%s,%d)\"\n", g.fils_gauche->cle,g.fils_gauche->valeur);
        write_edge(writer, *(g.fils_gauche), ninv);
    }
    else
    {
        fprintf(writer, "I%d [style=invis]\n", *ninv);
        fprintf(writer, "\"(%s,%d)\" -> I%d [style=invis]\n", g.cle, g.valeur, *ninv);
        (*ninv)++;
    }
    fprintf(writer, "I%d [style=invis]\n", *ninv);
    fprintf(writer, "\"(%s,%d)\" -> I%d [style=invis]\n", g.cle, g.valeur, *ninv);
    (*ninv)++;
    if (g.fils_droit != NULL)
    {
        fprintf(writer, "\"(%s,%d)\"", g.cle,g.valeur);
        fprintf(writer, " -> ");
        fprintf(writer, "\"(%s,%d)\"\n", g.fils_droit->cle,g.fils_droit->valeur);
        write_edge(writer, *(g.fils_droit), ninv);
    }
    else
    {
        fprintf(writer, "I%d [style=invis]\n", *ninv);
        fprintf(writer, "\"(%s,%d)\" -> I%d [style=invis]\n", g.cle, g.valeur, *ninv);
        (*ninv)++;
    }
}

void view(abrNoeud g)
{
    FILE *writer = fopen("temp.gv", "w");
    int n = 0;
    fprintf(writer, "digraph mygraph {\n");
    write_edge(writer, g, &n);
    fprintf(writer, "}\n");
    fclose(writer);
    system("xdot temp.gv &");
}

int main()
{
    abrNoeud* g1 = creer_noeud("a", 1, NULL, NULL);
    abrNoeud* g2 = creer_noeud("b", 2, NULL, NULL);
    abrNoeud* g3 = creer_noeud("c", 3, g1, g2);
    view(*g3);
}