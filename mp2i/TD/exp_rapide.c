#include <stdio.h>
#include <stdio.h>

// exponentiation rapide iteratif
float expo(float a, int n){
    float cp = a;
    float res = 1;
    while (n!=0){
        if (n%2==1){
            res = res*cp;}
        cp = cp*cp;
        n=n/2;}
    return res;}

int main()
{
    int n;
    float a;
    printf("a=");
    scanf("%f", &a);
    printf("n=");
    scanf("%d", &n);
    printf("exp (rapide itératif) a^n=%f\n", expo(a, n));
}