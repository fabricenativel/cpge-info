#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int value(char c)
{
    return (int)(c - '0');
}

bool is_digit(char c)
{
    return '0' <= c && c <= '9';
}

int myAtoi(char *s)
{
    int idx = 0;
    int ls = strlen(s);
    long int num = 0;
    bool sign;
    while (idx < ls && s[idx] == ' ')
    {
        idx++;
    }
    if (idx == ls && !is_digit(s[idx]) && s[idx] != '+' && s[idx] != '-')
    {
        return 0;
    }
    if (s[idx] == '-')
    {
        sign = true;
        idx++;
    }
    else if (s[idx] == '+')
    {
        sign = false;
        idx++;
    }
    else
    {
        sign = false;
    }
    while (idx < ls && is_digit(s[idx]))
    {
        // printf("Num = %d -- Remaining = %d\n",num,remaining);
        num = num * 10 + value(s[idx]);
        if (!sign && num > INT_MAX)
        {
            return INT_MAX;
        }
        if (sign && -num < INT_MIN)
        {
            return INT_MIN;
        }
        idx++;
    }
    if (sign)
    {
        return -num;
    }
    else
    {
        return num;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Utilisation : %s <chaine>\n", argv[0]);
    }
    else
    {
        int res = myAtoi(argv[1]);
        printf("%d\n", res);
    }
}