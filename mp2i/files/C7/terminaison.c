#include <stdio.h>
#include <assert.h>

/* Renvoie le quotient dans la division euclidienne de a par b avec a et b deux entiers naturels et b non nul  */
int quotient(int a,  int b)
{   assert (a>=0 && b>0);
    int q = 0;
    while (a - b >= 0)
    {
        a = a - b;
        q = q + 1;
    }
    return q;
}

int main()
{
    printf("Quotient de 2025 par 15 = %d\n",quotient(2025,15));
}