#include <stdio.h>

int main()
{
    float s = 0;
    for (int i = 1; i < 10000; i++)
    {
        s = s + 1 / i;
    }
    printf("somme =%f\n", s);
}