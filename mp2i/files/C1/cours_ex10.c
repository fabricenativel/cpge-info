#include <stdio.h>
#include <string.h>

int main()
{
    char test[] = "langage c";
    test[0] = 'L';
    test[8] = 'C';
    printf("%s \n",test);
    printf("Longueur = %ld\n",strlen(test));
}