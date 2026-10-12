#include <stdio.h>

int fibo_rec(int n) {
    if (n <= 1) { return n; }
    return fibo_rec(n - 1) + fibo_rec(n - 2);
}


int main()
{
    printf("fibo(10)=%d\n",fibo_rec(10));
}