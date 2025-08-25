#include <stdlib.h>
#include <stdio.h>

#define TMAX 100

struct test_s
{
    int val[TMAX];
};

int main()
{
    const int x;
    int y = x + 42;
    printf("y = %d \n",y);
    return 0;
}