#include <stdio.h>

struct objet
{
    int poids;
    int valeur;
};
typedef struct objet objet;


int memo[671][25];

int vmax(objet lo[], int p, int k)
{
    int c1,c2;
    if (k==0 || p==0) {return 0;}
    if (memo[p][k]!=-1) {return memo[p][k];}
    if (lo[k].poids>p) {memo[p][k]=vmax(lo,p,k-1); return vmax(lo,p,k-1);}
    c1 = vmax(lo,p-lo[k].poids,k-1)  + lo[k].valeur;
    c2 = vmax(lo,p,k-1);
    if (c1>c2)
    {
        memo[p][k]=c1;
        return c1;
    }
    memo[p][k]=c2;
    return c2;
}

void reconstruction(objet lo[], int p, int k)
{
    if (k>=0 && p>0){
    if (memo[p-lo[k].poids][k-1]+lo[k].valeur>=memo[p][k-1])
    {
        printf("Objet %d utilisé (poids = %d, valeur = %d) \n",k,lo[k].poids,lo[k].valeur);
        reconstruction(lo,p-lo[k].poids,k-1);
    }
    else
    {
        reconstruction(lo,p,k-1);
    }}
}

int main()
{
    objet lo[25];
    FILE * reader = fopen("objets.txt","r");
    for (int i=0; i<671;i++)
    {
        for (int j=0; j<25; j++)
        {
            memo[i][j]=-1;
        }
    }
    for (int i=1; i<25;i++)
    {
        fscanf(reader,"%d,%d\n",&lo[i].poids,&lo[i].valeur);
    }
    printf("Valeur maximale = %d\n",vmax(lo,670,24));
    printf("Valeur mémoïsée : %d\n",memo[670][24]);
    reconstruction(lo,670,24);
}