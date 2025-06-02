#include <stdio.h>
// S(n+1) = S(n)/2 si n est pair et 3S(n)+1 sinon
int syracuse(int n)     {
    if (n%2 == 0)
        {return n/2; }
    else
        {return 3*n+1; }}

int main()
{ printf("Syracuse 25 = %d \n",syracuse(25));
 return 0;}