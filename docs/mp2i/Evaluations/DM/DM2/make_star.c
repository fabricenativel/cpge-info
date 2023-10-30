#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

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


bool rand_bool()
{
    if (rand()%2==0) return true; else return false;

}

int main()
{
    srand(time(NULL));
    bool (*know)[SIZE] = malloc(sizeof(*know)*SIZE);
    int snumber = rand()%SIZE;
    int jnots;
    //les autres soit connaissent qqun soit ne sont pas connus de qqun
    for (int i=0;i<SIZE;i++)
    {
        for (int j=0;j<SIZE;j++)
        {       
            if (i!=j) know[i][j]=rand_bool(); else  know[i][j]=true;  
        }
        jnots = rand()%SIZE; // indice ou différence avec star
        if (rand_bool())
            know[i][jnots] = true;
        else
            know[jnots][i] = false;
    }
    //la start ne connait personne et est connu de tous
    for (int i=0;i<SIZE;i++)
    {
        know[snumber][i]=false;
        know[i][snumber]=true;
    }
    FILE * writer = fopen("star.txt","w");
    for (int i=0;i<SIZE;i++)
    {
        for (int j=0;j<SIZE;j++)
        {   
            if (know[i][j])
            { fprintf(writer,"%c",'1');}
            else
            { fprintf(writer,"%c",'0');}
        }
        fprintf(writer,"%c",'\n');
    }
    fclose(writer);
    printf("La star est en ligne %d\n",snumber);
}