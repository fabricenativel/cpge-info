#include <stdio.h>
#include <math.h>


double vn(int n, double a, double b);

double un(int n, double a, double b){
    if (n==0)
    {return a;}
    return sqrt(un(n-1,a,b)*vn(n-1,a,b));}

double vn(int n,double a, double b){ 
    if (n==0)
    {return b;}
    return (un(n-1,a,b)+vn(n-1,a,b))/2;}

int main()
{
    printf("u10=%f\n",un(10,3,7));
    printf("v10=%f\n",vn(10,3,7));
}