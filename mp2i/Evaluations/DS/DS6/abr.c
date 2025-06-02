#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct abrNoeud_s
{
    char *cle;
    int valeur;
    struct abrNoeud_s *fils_gauche;
    struct abrNoeud_s *fils_droit;
};
typedef struct abrNoeud_s abrNoeud;

char *copie_chaine(char *s)
{
    // On calcule la longueur l de la chaine
    int l = 0;
    while (s[l] != '\0')
    {
        l++;
    }
    // On alloue l'espace pour la nouvelle chaine
    char *s2 = malloc((l + 1) * sizeof(char));
    // On recopie caractère par caractère
    for (int i = 0; i <= l; i++)
    {
        s2[i] = s[i];
    }
    return s2;
}

abrNoeud *creer_noeud(char *cle, int valeur, abrNoeud *fg, abrNoeud *fd)
{
    abrNoeud *noeud = malloc(sizeof(abrNoeud));
    noeud->cle = copie_chaine(cle);
    noeud->valeur = valeur;
    noeud->fils_gauche = fg;
    noeud->fils_droit = fd;
    return noeud;
}

int hauteur(abrNoeud *ab)
{
    if (ab == NULL)
    {
        return -1;
    }
    int hg = hauteur(ab->fils_gauche);
    int hd = hauteur(ab->fils_droit);
    if (hg > hd)
    {
        return 1 + hg;
    }
    else
    {
        return 1 + hd;
    }
}

int equilibre(abrNoeud *ab)
{
    int h_g = hauteur(ab->fils_gauche);
    int h_d = hauteur(ab->fils_droit);
    return (h_g - h_d);
}

void write_edge(FILE *writer, abrNoeud g, int *ninv)
{
    if (g.fils_gauche != NULL)
    {
        fprintf(writer, "\"(%s,%d)\"", g.cle, g.valeur);
        fprintf(writer, " -> ");
        fprintf(writer, "\"(%s,%d)\"\n", g.fils_gauche->cle, g.fils_gauche->valeur);
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
        fprintf(writer, "\"(%s,%d)\"", g.cle, g.valeur);
        fprintf(writer, " -> ");
        fprintf(writer, "\"(%s,%d)\"\n", g.fils_droit->cle, g.fils_droit->valeur);
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

int compare_chaine(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] < s2[i])
        {
            return -1;
        }
        else if (s1[i] > s2[i])
        {
            return 1;
        }
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0')
    {
        return 0;
    }
    else if (s1[i] == '\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int abr_rechercher(abrNoeud *a, char *clef)
{
    // Ce cas ne devrait jamais se produire car on suppose la clé présente
    if (a == NULL)
    {
        return -1;
    }
    int cmp = compare_chaine(clef, a->cle);
    if (cmp == 0)
    {
        return a->valeur;
    }
    else if (cmp < 0)
    {
        return abr_rechercher(a->fils_gauche, clef);
    }
    else
    {
        return abr_rechercher(a->fils_droit, clef);
    }
}

int hachage(char *s)
{
    int h = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        h += (i + 1) * (int)s[i];
        i += 1;
    }
    return h;
}

int main()
{
    abrNoeud *g1 = creer_noeud("a", 1, NULL, NULL);
    abrNoeud *g2 = creer_noeud("c", 3, NULL, NULL);
    abrNoeud *g3 = creer_noeud("b", 2, g1, g2);
    printf("Equilibre = %d\n", equilibre(g3));
    printf("Valeur trouvée = %d\n", abr_rechercher(g3, "c"));
    printf("Hache de \"abc\" = %d\n", hachage("abc"));
}