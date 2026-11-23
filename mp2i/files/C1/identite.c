#include <stdio.h>
#include <stdbool.h>

void identite(int n)
{
    //Affiche la matrice identité
    bool id[n][n];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            id[i][j] = false;
        }
        id[i][i]=true;
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (id[i][j])
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");
    }
}

int main()
{
    identite(4);
}