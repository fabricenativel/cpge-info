#include <stdio.h>

float division(float num, float den){
    float res = num/den;
    return res;}

int main(){   
    float deux_tiers= division(2,3);
    printf("2/3 = %f\n",deux_tiers);
    return 0;}