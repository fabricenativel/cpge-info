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

void read(bool know[])
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
                know[SIZE*i+j] = false;
            }
            else
            {
                know[SIZE*i+j] = true;
            }
        }
        fgetc(reader);
    }
}


bool is_star(bool know[],int lig)
{
    for (int j=0;j<SIZE;j++)
    {
        if ((j!=lig && know[lig*SIZE+j]) || (j!=lig && !know[j*SIZE+lig]))
        {
            return false;
        }
    }
    return true;
}

int star_naif(bool know[])
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

int get_star(bool know[])
{
    int i=0, j=SIZE-1;
    while (i!=j)
    {
        if (know[i*SIZE+j]) // si ii connait jj alors ii n'est pas la star on l'élimine
        {
            i = i+1;
        }
        else  // ii ne connait pas jj donc, jj n'est pas la star
        {  
            j = j-1;
        }
    }
    return  i;
}

int main()
{
    bool *know =  malloc(sizeof(bool)*SIZE*SIZE);
    read(know);
    //affiche(know);
    printf("Star en %d\n",get_star(know));
    printf("Star en %d\n",star_naif(know));
    free(know);
}