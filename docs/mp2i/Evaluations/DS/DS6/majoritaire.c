#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int maximum(int tab[], int n)
{
    int maxi = tab[0];
    for (int i = 1; i < n; i++)
    {
        if (tab[i] > maxi)
        {
            maxi = tab[i];
        }
    }
    return maxi;
}

int vote_majoritaire_bug(int votes[], int nb_votes)
{
    int nb_candidats = 1 + maximum(votes, nb_votes);
    int voix[nb_candidats];
    for (int i = 0; i < nb_votes; i++)
    {
        voix[votes[i]] = voix[votes[i]] + 1;
    }
    for (int c = 0; c < nb_candidats; c++)
    {
        if (voix[c] > nb_votes / 2)
        {
            return c;
        }
    }
    return -1;
}

int main()
{
    int ex1[] = {1, 0, 2, 0, 0};
    int ex2[] = {1, 0, 2, 1, 0};
    int ex3[] = {1, 0, 1, 2, 1, 2};
    printf("Ex 1 : %d\n", vote_majoritaire(ex1, 5));
    printf("Ex 2 : %d\n", vote_majoritaire(ex2, 5));
    printf("Ex 3 : %d\n", vote_majoritaire(ex3, 6));
}