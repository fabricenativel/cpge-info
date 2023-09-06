#include <stdio.h>


void triangle(int hauteur, char car)
{
    int nb_space = hauteur - 1;
    for (int h=0;h<hauteur;h++)
    {
        for (int k=0; k<nb_space;k++)
        {
            printf(" ");
        }
        for (int k=0; k<2*(hauteur-nb_space)-1;k++)
        {
            printf("%c",car);
        }
        nb_space--;
        printf("\n");
    }
}

void rectangle_creux(int largeur, int longueur, char car)
{
    for (int lig=0;lig<largeur;lig=lig+1)
    {
        for (int col=0;col<longueur;col=col+1)
        {
            if (col==0 || col==longueur-1 || lig==0 || lig==largeur-1)
            {
                printf("%c",car);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}


void carre_plein(int cote, char car)
{
    
}
int main()
{
    triangle(6,'*');
    return 0;
}