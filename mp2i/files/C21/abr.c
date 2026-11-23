#include <stdio.h>
#include <stdlib.h>

struct noeud_s
{
    int valeur;
    struct noeud_s *sag;
    struct noeud_s *sad;
};
typedef struct noeud_s noeud;
typedef noeud *arbrebin;

int main()
{
    return 0;
}