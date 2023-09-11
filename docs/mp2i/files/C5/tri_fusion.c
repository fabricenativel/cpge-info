#include <stdio.h>
#include <stdlib.h>

void affiche(int tab[], int size)
{
    printf("{");
    for (int i=0; i<size-1; i++)
    {
        printf("%d,",tab[i]);
    }
    if (size>0)
    {
        printf("%d",tab[size-1]);
    }
    printf("}");
}

int* fusion(int tab1[], int size1, int tab2[], int size2)
{
    int *tab = malloc(sizeof(int)*(size1+size2));
    int i1 = 0;
    int i2 = 0;
    int i = 0;
    while (i1<size1 || i2<size2)
    {
        if ((i2>=size2) || (i2<size2 && i1<size1 && tab1[i1]<tab2[i2]))
        {   
            tab[i] = tab1[i1];
            i1 = i1 +1;
        }
        else
        {
            tab[i] = tab2[i2];
            i2 = i2+1;
        }
        i = i+1;
    }
    return tab;
}

void separe(int tab[], int tab1[], int size1, int tab2[], int size2)
{
    for (int i1=0;i1<size1;i1++)
    {
        tab1[i1]=tab[i1];
    }
    for (int i2=0;i2<size2;i2++)
    {
        tab2[i2]=tab[size1+i2];
    }

}

int* tri_fusion(int tab[], int size)
{
    if (size>1)
    {
    int size1 = size/2;
    int size2 = size - size1;
    int *res;
    int *tri1;
    int *tri2;
    int tab1[size1];
    int tab2[size2];
    separe(tab, tab1, size1, tab2, size2);
    tri1 = tri_fusion(tab1,size1);
    tri2 = tri_fusion(tab2,size2);
    res = fusion(tri1,size1,tri2,size2);
    free(tri1);
    free(tri2);
    return res;}
    else
    {
        int *res=malloc(sizeof(int)*size);
        if (size == 1) {res[0]=tab[0];}
        return res;
    } 
}

int main()
{   int size = 1000000;
    //printf("taille du tableau =");
    //scanf("%d",&size);
    int *test = malloc(sizeof(int)*size);
    for (int i=0;i<size;i++)
    {
        test[i] = rand()%(size*5);
    }
    int *tri;
    tri = tri_fusion(test,size);
    //affiche(tri,size);
    //printf("\n");
    free(tri);
    free(test);
}