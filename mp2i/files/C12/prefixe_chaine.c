#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct noeud
{
    struct noeud *sag;
    int valeur;
    struct noeud *sad;
};
typedef struct noeud noeud;
typedef noeud *ab;
        
struct maillon
{
    int valeur;
    struct maillon * suivant;
};
typedef struct maillon maillon;
struct liste
{
    maillon* deb;
    maillon* fin;
};
typedef struct  liste liste;




int ninv = 0;

ab cree_arbre(ab g, int v, ab d)
{
    noeud *n = malloc(sizeof(noeud));
    n->sag = g;
    n->valeur = v;
    n->sad = d;
    return n;
}

int taille(ab a)
{
    if (a == NULL)
    {
        return 0;
    }
    return 1 + taille(a->sag) + taille(a->sad);
    ;
}

bool est_vide(ab a)
{
    return (a == NULL);
}

void write_edge(FILE *writer, ab g)
{
    if (g->sag != NULL)
    {
        fprintf(writer, "%d", g->valeur);
        fprintf(writer, " -> ");
        fprintf(writer, "%d\n", g->sag->valeur);
        write_edge(writer, g->sag);
    }
    else
    {
        fprintf(writer, "I%d [style=invis]\n", ninv);
        fprintf(writer, "%d -> I%d [style=invis]\n", g->valeur, ninv);
        ninv++;
    }
    fprintf(writer, "I%d [style=invis]\n", ninv);
    fprintf(writer, "%d -> I%d [style=invis]\n", g->valeur, ninv);
    ninv++;
    if (g->sad != NULL)
    {
        fprintf(writer, "%d", g->valeur);
        fprintf(writer, " -> ");
        fprintf(writer, "%d\n", g->sad->valeur);
        write_edge(writer, g->sad);
    }
    else
    {
        fprintf(writer, "I%d [style=invis]\n", ninv);
        fprintf(writer, "%d -> I%d [style=invis]\n", g->valeur, ninv);
        ninv++;
    }
}

void view(ab g)
{
    char buf[256];
    int n;
    FILE *writer = fopen("temp.gv", "w");
    FILE *imgwriter = fopen("temp.jpg", "wb");
    fprintf(writer, "digraph mygraph {\n");
    write_edge(writer, g);
    fprintf(writer, "}\n");
    fclose(writer);
    FILE *dotresult = popen("dot temp.gv -Tjpg", "r");
    if (dotresult == NULL)
    {
        printf("Bug !\n");
    }
    while ((n = fread(buf, 1, 256, dotresult)) != 0)
    {
        fwrite(buf, 1, n, imgwriter);
    }
    pclose(dotresult);
    fclose(imgwriter);
    system("eog temp.jpg &");
}



void ajoute(liste *l, int v)
{
    maillon* nl=malloc(sizeof(maillon));
    nl->suivant = l->deb;
    nl->valeur =v;
    l->deb = nl;
    if (l->fin == NULL)
    {l->fin = l->deb;
    }
}

void concatene(liste *l1, liste *l2)
{
    if (l2->deb != NULL)
    {
    if (l1->fin!=NULL)
    {l1->fin->suivant = l2->deb;
    l1->fin = l2->fin;}
    else
    {l1->deb = l2->deb;
    l1->fin = l2->fin;
    }
    }  
}

liste liste_vide()
{
    liste l = {.deb=NULL, .fin=NULL};
    return l;
}

liste prefixe(ab a)
{
    if (a!=NULL) 
    {
        liste lg = prefixe(a->sag);
        liste ld = prefixe(a->sad);
        concatene(&lg, &ld);
        ajoute(&lg, a->valeur);
        return lg;
    }
    else
    {
        liste l = liste_vide();
        return l;
    }
}
void view_list(liste l)
{
    printf("-> ");
    while (l.deb!=NULL)
    {
        printf("%i -> ",l.deb->valeur);
        l.deb = l.deb->suivant;
    }
    printf("null \n");
}


void libere(ab *a)
{
    ab sag;
    ab sad;
    if (*a != NULL)
    {
        sag = (*a)->sag;
        sad = (*a)->sad;
        libere(&sag);
        libere(&sad);
        free(*a);
        *a = NULL;
    }
}

ab arbre_aleatoire(int n, int val)
{
    if (n == 0)
    {
        return NULL;
    }
    int k = rand() % n;
    ab sag = arbre_aleatoire(k, val + 1);
    ab sad = arbre_aleatoire(n - k - 1, val + k + 1);
    return cree_arbre(sag, val, sad);
}

void insere_noeud(ab *t, int v)
{
    if (*t == NULL)
    {
        *t = cree_arbre(NULL, v, NULL);
    }
    else
    {
        if (rand() % 2 == 0)
        {
            insere_noeud(&((*t)->sag), v);
        }
        else
        {
            insere_noeud(&((*t)->sad), v);
        }
    }
}

ab aleatoire(int n)
{
    ab t = NULL;
    for (int i = 0; i < n; i++)
    {
        insere_noeud(&t, i);
    }
    return t;
}

int main()
{
    srand(time(NULL));
    ab t = aleatoire(10);
    view(t);
    view_list(prefixe(t));
    printf("\n");
}