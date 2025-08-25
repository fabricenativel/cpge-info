struct noeud
{
    struct noeud *sag;
    int valeur;
    struct noeud *sad;
};
typedef struct noeud noeud;
typedef noeud *ab;
