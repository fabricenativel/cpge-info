#include <string.h>
#include <stdio.h>

unsigned hash(char s[])
{
    unsigned h = 0;
    for (int i=0;i<strlen(s);s++)
    {
        h = 31*h + (unsigned) s[i];
    }
    return h;
}

int main()
{
    char test[] = "bidule";
    printf("Valeur du hash de %s = %u\n",test,hash(test));
}