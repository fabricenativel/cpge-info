#include <stdio.h>

float puissance_iteratif(float a, int n){
    float p = 1.0;
    for (int k = 1; k <= n; k = k + 1){
        p = p * a;}
    return p;}

float puissance_recursif(float a, int n){
    if (n == 0){
        return 1;}
    else{
        return a * puissance_recursif(a, n - 1);}}

float puissance_acc(float a, int n, float acc){
    if (n == 0) {
        return acc;}
    else {
        return puissance_acc(a, n - 1, acc * a);}}

float puissance_rapide(float a, int n){
    if (n == 0){
        return 1;}
    else {
        float pr = puissance_rapide(a, n / 2);
        if (n % 2 == 0){
            return pr * pr;}
        else{
            return pr * pr * a;}}}

int main()
{
    int n;
    float a;
    printf("a=");
    scanf("%f", &a);
    printf("n=");
    scanf("%d", &n);
    printf("a^n=%f\n", puissance_rapide(a, n));
}