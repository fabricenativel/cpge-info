#include <stdio.h>


int main()
{
    char *s1 = "arbre";
    char s2[] = "arbre";
    s1[0] = 'A';
    printf("%s\n",s1);
}