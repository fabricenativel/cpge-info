#include <stdio.h>

void triangle(char c, int n)
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=i;j++)
        {
            printf("%c",c);
        }
        printf("\n");
    }
    return 2;
}   

int main()
{
    triangle('*',12);
}