void prefixe(ab a)
{
    if (a != NULL)
    {
        printf("%d ", a->valeur);
        prefixe(a->sag);
        prefixe(a->sad);
    }
}
