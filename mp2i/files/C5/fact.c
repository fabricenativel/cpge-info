#include <stdio.h>

 int fact_iter( int n){
     int res = 1;
    for ( int i=1;i<=n;i++){
        res = res * i;}
    return res;}

 int fact_rec( int n){
    if (n==0)
        {return 1;}
    return n*fact_rec(n-1);}

 int fact_acc( int n,  int acc){
    if (n==0)
        {return acc;}
    return fact_acc(n-1,n*acc);}

 int main()
{
     int n;
    printf("n=");
    scanf("%d",&n);
    printf("n!=%d\n",fact_acc(n,1));
    printf("n!=%d\n",fact_rec(n));
    return 0;
}