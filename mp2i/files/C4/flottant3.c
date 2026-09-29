# include <stdio.h>

# define N 999999

int main(int argc, char* argv[])
{
    double croissant = 0.0;
    double decroissant = 0.0;
    int j;
    for (int i=1;i<=N;i++)
    {
        croissant += 1.0/(i*(i+1));
        j = N+1-i;
        decroissant += 1.0/(j*(j+1));
    }
    printf("Erreur somme dans l'ordre croissant   = %.16f \n",croissant-1+1.0/(N+1));
    printf("Erreur somme dans l'ordre décroissant = %.16f \n",decroissant-1+1.0/(N+1));
}