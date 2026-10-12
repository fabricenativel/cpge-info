#include <stdio.h>
#include <stdlib.h>


int max3(int a, int b, int c)
{
    if (a>b && a>c) return a;
    if (b>c) return b;
    return c;
}

// Maximum des tranches qui contiennent l'élément d'indice k
int max_tranchek(int tab[],int start, int k, int end)
{
    int sk_max_left = tab[k];
    int sk_max_right = tab[k];
    int sk;
    // Tranche qui se termine en k
    sk = tab[k];
    for (int i=k-1;i>=start;i--)
    {
        sk = sk+tab[i];
        if (sk>sk_max_left) {sk_max_left = sk;}
    }
    // Tranche qui commence en k
    sk = tab[k];
    for (int i=k+1;i<end;i++)
    {
        sk = sk+tab[i];
        if (sk>sk_max_right) {sk_max_right = sk;}
    }
    return sk_max_left+sk_max_right-tab[k];
}

int somme_maxi_aux(int tab[], int size, int start, int end) {
    if (end==start) 
        {return tab[start];}
    if (end==start+1) 
        {return max3(tab[start],tab[end],tab[start]+tab[end]);}
    int s1, s2, s3;
    int mid = (start+end)/2;
    s1 = somme_maxi_aux(tab, size, start, mid-1);
    s2 = max_tranchek(tab,start,mid,end);
    s3 = somme_maxi_aux(tab, size, mid+1, end);
    return max3(s1,s2,s3);}

int smax_dpr(int tab[], int size)
{
    return somme_maxi_aux(tab,size,0,size-1);
}

int* random_tab(int seed, int size, int minvalue, int maxvalue)
{
    srand(seed);
    int *tab = malloc(sizeof(int)*size);
    for (int i=0;i<size;i++)
    {
        tab[i] = minvalue + rand()%(maxvalue-minvalue+1);
    }
    return tab;
}

void view_tab(int tab[], int size)
{
    printf("[");
    for (int i=0;i<size-1;i++)
    {
        printf("%d, ",tab[i]);
    }
    printf("%d]\n",tab[size-1]);
}

int smax_bf(int tab[], int size)
{
    int smax = tab[0];
    int s;
    for (int i=0;i<size;i++)
    {
        s=0;
        for (int j=i;j<size;j++)
        {
            s = s + tab[j];
            if (s>smax)
            {
                smax =s;
            }
            
        }
    }
    return smax;
}

int main()
{
    int seed = 42;
    int size = 1000;
    int *test = random_tab(seed,size,-500, 500);
    printf("Solution par force brute : %d \n",smax_bf(test,size));
    printf("Solution par diviser pour régner : %d \n",smax_dpr(test,size));
    free(test);
}