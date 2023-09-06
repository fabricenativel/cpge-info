#include <stdio.h>

int my_strlen(char str[])
{
    int l = 0;
    while (str[l]!='\0')
    {l++;}
    return l;
}

int main()
{
    char test[] = "Bonjour !";
    printf("Longueur = %d\n",my_strlen(test));
    test[0]='b';
    printf("%s",test);
}