#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int max(int a, int b, int c)
{
    if (a > b && a > c)
        return a;
    if (b > c)
        return b;
    return c;
}

bool est_triangle(int a, int b, int c)
{
    int m = max(a, b, c);
    if (m <= a + b + c - m)
        return true;
    return false;
}

bool est_isocele(int a, int b, int c)
{
    return (a == b || a == c || b == c);
}

bool est_equilateral(int a, int b, int c)
{
    return (a == b && b == c);
}

bool est_rectangle(int a, int b, int c)
{
    int m = max(a, b, c);
    return m * m == a * a + b * b + c * c - m * m;
}

int main(int argc, char *argv[])
{
    int a, b, c;
    if (argc != 4)
    {
        printf("Prend en argument trois entiers sur la ligne de commande\n");
    }
    else
    {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        c = atoi(argv[3]);
        printf("a=%d, b=%d; c=%d\n",a,b,c);
        if (est_triangle(a, b, c))
        {
            if (est_equilateral(a, b, c))
            {
                printf("Triangle équilatéral \n");
            }
            else
            {
                if (est_isocele(a, b, c) && est_rectangle(a, b, c))
                {
                    printf("Triangle rectangle et isocèle \n");
                }
                else
                {
                    if (est_isocele(a, b, c))
                    {
                        printf("Triangle isocèle\n");
                    }
                    if (est_rectangle(a, b, c))
                    {
                        printf("Triangle rectangle\n");
                    }
                }
            }
        }
        else
        {
            printf("Ne sont pas les trois côtés d'un triangle\n");
        }
    }
}