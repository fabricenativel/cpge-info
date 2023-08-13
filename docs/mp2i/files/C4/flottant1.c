# include <stdio.h>

int main()
{
    double x = 0;
    int nb_tours = 0;
    while (x!=1.0)
    {
        x = x + 0.25;
        nb_tours = nb_tours + 1;
    }
    printf("Sortie après %d tours de boucle\n",nb_tours);
}