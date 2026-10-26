#include <stdio.h>


void ligne(int size)
{
    for (int j=1;j<=size;j++)
        {
            printf("*");
        }
        printf("\n");
}

void triangle_iter(int n){
    for (int i=n;i>=1;i--)
    {ligne(i);}
    }

void triangle_rec(int n) {
    if (n>0)
        {ligne(n);
         triangle_rec(n-1);}
    }   

int main()
{
    triangle_iter(5);
}
