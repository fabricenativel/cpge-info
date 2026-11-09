#include <stdio.h>
// S(n) = n/2 si n est pair et 3*n+1 sinon
int syracuse(int n)
{
    if (n % 2 == 0) //(% est l'opérateur modulo, == le test d'égalité)
    {
        return n / 2;
    }
    else
    {
        return 3 * n + 1;
    }
}
int main()
{
    int n = 42;
    printf("Syracuse(%d) = %d \n",n, syracuse(n));
}