#include <stdio.h>
#include <assert.h>

int main()
{
    int a = 42;
    assert (a != 42);
    int b = ++a;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
}