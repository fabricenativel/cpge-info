#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double somme = 0.0;
    for (int i = 1; i < argc; i++)
    {
        somme = somme + atof(argv[i]);
    }
    printf("%f\n", somme / (argc - 1));
}