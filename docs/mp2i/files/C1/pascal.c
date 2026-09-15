#include <stdio.h>

void pascal(int n)
{
    //Affiche les n premières lignes du triangle de Pascal
    if (n>0)
    {
        int courante[n];
        int suivante[n];
        courante[0] = 1;
        for (int i=0; i<n; i++)
        {
            for (int j=0;j<i;j++)
            {
                printf("%d ",courante[j]);
                if (j==0)
                {
                    suivante[j] = 1;
                }
                else
                {
                    suivante[j] = courante[j-1] + courante[j];
                }
            }
            printf("\n");
            for (int j=0;j<i;j++)
            {
                courante[j] = suivante[j];
            }
            courante[i] = 1;
        }
    }
}

int main()
{
    pascal(10);
}