#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool est_solution(int tab[], int size)
{
    for (int i=1;i<size;i++)
    {
        for (int j=0;j<i;j++)
        {
            if (abs(tab[j]-tab[i])==i-j)
            {
                return false;
            }
        }
    }
    return true;
}

void echange(int tab[], int i , int j)
{
    int temp = tab[i];
    tab[i]=tab[j];
    tab[j] = temp;
}

int nb_solutions(int size)
{
    int tab[size];
    int c[size];
    int i=0;
    int nb = 0;
    for (int i=0;i<size;i++)
    {
        c[i]=0;
        tab[i]=i;
    }
    while (i<size)
    {
        if (c[i]<i)
        {
            if (i%2==0)
            {
                echange(tab,0,i);
            }
            else
            {
                echange(tab,c[i],i);
            }
            if (est_solution(tab,size))
            {
                nb++;
            }
            c[i]++;
            i=1;
        }
        else
        {
            c[i]=0;
            i++;
        }
    }
    return nb;
}

int main(int argc, char* argv[])
{
    if (argc!=2)
    {
        printf("Usage : %s <size>\n",argv[0]);
        return 1;
    }
    int size = atoi(argv[1]);
    printf("Nombre de solution pour %d reines = %d \n",size,nb_solutions(size));
}