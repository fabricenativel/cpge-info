#include <stdint.h>
#include <stdio.h>
#include <string.h>

int num(char c)
{
    if (c >= 65 && c <= 90)
    {
        return c - 64;
    }
    if (c >= 97 && c <= 122)
    {
        return c - 70;
    }
    if (c >= 48 && c <= 57)
    {
        return c + 5;
    }
    if (c == '_')
    {
        return 63;
    }
    return 64;
}

uint64_t hash(char *s)
{
    uint64_t h = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        h = h * 32 + num(s[strlen(s) - 1 - i]);
    }
    return h;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Utilisation : %s <chaine>\n", argv[0]);
    }
    else
    {
        uint64_t h = hash(argv[1]);
        printf(" Hash de %s = %ld\n", argv[0], h);
    }
}