#include <stdio.h>

int main()
{
    const int n = 42;
    int * m = &n;
    *m =53;
    printf("n=%d\n",n);
}