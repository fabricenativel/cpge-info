#include <stdio.h>
#include <stdbool.h>

bool tous_egaux(int tab[], int size)
{
    for (int i = 0; i < size; i = i + 1)
    {
        if (tab[i] != tab[i + 1])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

bool tous_egaux(int tab[], int size)
{
    for (int i = 0; i < size - 1; i = i + 2)
    {
        if (tab[i] != tab[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t[4] = {2, 2, 3, 3};
    bool b1 = tous_egaux_v1(t, 4);
    bool b2 = tous_egaux_v2(t, 4);
    if (b1)
    {
        printf("ok v1\n");
    }
    else
    {
        printf("pas ok v1\n");
    }
    if (b2)
    {
        printf("ok v1\n");
    }
    else
    {
        printf("pas ok v2\n");
    }
}