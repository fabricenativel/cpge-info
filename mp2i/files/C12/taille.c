int taille(ab a)
{
    if (a == NULL)
    {
        return 0;
    }
    return 1 + taille(a->sag) + taille(a->sad);
}
