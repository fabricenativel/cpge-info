#include <stdio.h>

int main()
{
    char t[] = "L'informatique c'est fantastique !";
    t[15]='C';
    printf("%s \n",t+15);
}