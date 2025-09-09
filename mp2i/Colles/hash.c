#include <stdio.h>
#include <stdint.h>

uint32_t hash(char *s)
{
    uint32_t h = 0;
    int index = 0;
    while (s[index]!='\0')
    {
        h = 31*h + s[index];
        index++;
    }
    return h;
}

int main()
{
    char s1[] = "AaBCAaBC";
    char s2[] = "BBAbBBAb";
    printf("Hash de %s = %u\n",s1,hash(s1));
    printf("Hash de %s = %u\n",s1,hash(s2));
}
