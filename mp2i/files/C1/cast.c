#include <stdio.h>

float division(int num, int den){
    float res = num/den;
    return res;}

int main(){   
    float deux_tiers= division(2,3);
    printf("2/3 = %f\n",deux_tiers);
    printf("%d\n",(int)13.6 % 2);
    return 0;}