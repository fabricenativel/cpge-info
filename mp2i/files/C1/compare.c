
#include <stdio.h>

int compare(int a, int b)
{
    if (a < b)
    {
        return -1;
    }
    else if (a == b)
    {
        return 0;
    }
    else
        return 1;
}

int main()
{
    printf("Résultat = %d \n", compare(2, 7));
}