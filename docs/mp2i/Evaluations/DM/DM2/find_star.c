#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const int SIZE=1000;


void affiche(bool know[SIZE][SIZE])
{
    for (int i=0;i<SIZE;i++)
    {
        for (int j=0;j<SIZE;j++)
        {
            printf("%d ",know[i][j]);
        }
        printf("\n");
    }
}

void read(bool know[SIZE][SIZE])
{
    FILE * reader = fopen("star.txt","r");
    char v;
    for (int i=0;i<SIZE;i++)
    {
        for (int j=0;j<SIZE;j++)
        {
            v = fgetc(reader);
            if (v=='0')
            {
                know[i][j] = false;
            }
            else
            {
                know[i][j] = true;
            }
        }
        fgetc(reader);
    }
}


bool is_star(bool know[SIZE][SIZE],int lig)
{
    for (int j=0;j<SIZE;j++)
    {
        if ((j!=lig && know[lig][j]) || (j!=lig && !know[j][lig]))
        {
            return false;
        }
    }
    return true;
}

int star_naif(bool know[SIZE][SIZE])
{
    for(int i=0;i<SIZE;i++)
    {
        if (is_star(know,i))
        {
            return i;
        }
    }
    return -1;
}

int get_star(bool know[][SIZE])
{
    int ii=0, jj=SIZE-1;
    while (ii!=jj)
    {
        if (know[ii][jj]) // si ii connait jj alors ii n'est pas la star on l'élimine
        {
            ii = ii+1;
        }
        else  // ii ne connait pas jj donc, jj n'est pas la star
        {  
            jj = jj-1;
        }
    }
    return  ii;
}

int main()
{
    bool test[1000][1000];
    bool (*know)[SIZE] =  malloc(sizeof(*know)*SIZE);
    read(know);
    //affiche(know);
    printf("Star en %d\n",get_star(know));
    printf("Star en %d\n",star_naif(know));
    free(know);
}