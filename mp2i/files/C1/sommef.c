#include <stdio.h>

float somme(float n, float m){
    return n+m;}

int main(){
    float n,m,s;
    printf("a=");
    scanf("%f",&n);
    printf("b=");
    scanf("%f",&m);
    s = somme(n,m);
    printf("a+b=%f\n",s);
    return 0;
    }