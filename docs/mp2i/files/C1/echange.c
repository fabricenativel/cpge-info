#include <stdio.h>

void echange(int a, int b){
    int temp = a;
    a = b;
    b= temp;}

int main(){
    int a = 12;
    int b = 50;
    echange(a,b);
    printf("a = %i\n",a);
    printf("b = %i\n",b);
    return 0;}