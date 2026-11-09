#include <stdio.h>
#include <stdlib.h>

int russe(int a, int b)
{
    // Renvoie ab en utilisant la technique de la multiplication à la russe
    int r = 0;
    while (a != 0)
    {
        if (a % 2 == 1)
        {
            r = r + b;
        }
        a = a / 2;
        b = b * 2;
    }
    return r;
}

int russe_rec(int a, int b)
{
    if (a == 0)
    {
        return 0;
    }
    int t = russe_rec(a / 2, 2 * b);
    if (a % 2 == 0)
    {
        return t;
    }
    return t + b;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Utilisation : %s <entier> <entier>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("%d\n", russe(a, b));
    printf("%d\n", russe_rec(a, b));
    return EXIT_SUCCESS;
}