ab cree_arbre(ab g, int v, ab d)
{
    noeud *n = malloc(sizeof(noeud));
    assert n!=NULL;
    n->sag = g;
    n->valeur = v;
    n->sad = d;
    return n;
}
