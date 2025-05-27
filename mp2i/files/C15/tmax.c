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
    return max3(sk_max_left,sk_max_right,sk_max_left+sk_max_right-tab[k]);
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

int somme_maxi(int tab[], int size)
{
    return somme_maxi_aux(tab,size,0,size-1);
}

int* read_tab(char filename[], int *tab_size)
{
    // Taille du tableau
    int size = 0;
    int n;
    FILE* reader = fopen(filename,"r");
    while (fscanf(reader,"%d\n",&n)!=EOF)
    {
        size = size + 1;
    }
    // Allocation et lecture
    int *tab = malloc(sizeof(int)*size);
    rewind(reader);
    for (int i=0;i<size;i++)
    {
        fscanf(reader,"%d\n",&tab[i]);
    }
    *tab_size = size;
    return tab;
}

int main(int argc,char *argv[])
{
    //int test[9] = {2, -7, -5, 4, -1, 10, -4, 9, -2};
    int *test;
    int test_size;
    if (argc!=2) {
        printf("Utilisation : ./algo1.exe filename");
    }
    else
    {
        test = read_tab(argv[1],&test_size);
        printf("Lecture terminée, %d éléments lus\n",test_size);
    }
    printf("Somme maximale d'une tranche = %d\n",somme_maxi(test,test_size));
    free(test);
}