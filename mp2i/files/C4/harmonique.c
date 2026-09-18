# include <stdio.h>

# define N 1000000000

int main(int argc, char* argv[])
{
    double croissant = 0.0;
    double decroissant = 0.0;
    int j;
    for (int i=1;i<=N;i++)
    {
        croissant += 1.0/i;
        j = N+1-i;
        decroissant += 1.0/j;
    }
    printf("Somme dans l'ordre croissant   = %.16f \n",croissant);
    printf("Somme dans l'ordre décroissant = %.16f \n",decroissant);
}