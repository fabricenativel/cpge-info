#include <stdio.h>

int get_imax(int tab[],int size) {
    int max = 0;
    int imax;
    for (int i=0; i<size; i++) {
        if (tab[i] >= max) {
            max = tab[i];
            imax = i;}}
    return imax;}

int main(){
    int test_tab[5] = {12,18,11,3,14};
    printf("Indice du max =%d",get_imax(test_tab,5));
    return 0;
}