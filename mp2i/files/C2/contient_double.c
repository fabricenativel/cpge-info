#include <stdio.h>
#include <stdbool.h>

bool contient_double(int tab[],int size){
    for (int i=0;i<size-1;i++){
        if (tab[i]==tab[i+1]){
            return true;}}
    return false;}

int main()
{   
    int test_tab[5] = {1,6,7,8,2};
    if (contient_double(test_tab,5))
    {printf("Contient un double");}
    else
    {printf("N'en contient par");}

    return 0;
}