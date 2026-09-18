#include <stdio.h>

int somme(int n, int m){
    return n+m;}

int main(){
    int n,m,s;
    printf("a=");
    scanf("%d",&n);
    printf("b=");
    scanf("%d",&m);
    s = somme(n,m);
    printf("a+b=%d\n",s);
    return 0;
    }