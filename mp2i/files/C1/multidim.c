#include <stdio.h>
#include <stdbool.h>

void affiche(bool m[][10], int l, int c)
{
    for (int i=0;i<l;i++)
    {
        for (int j=0;j<c;j++)
        {
            if (m[i][j])
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    bool ex1[10][10] = {false}; // une matrice 10x10 de booléens
    ex1[3][5] = true; 
    affiche(ex1, 10, 10);
}