#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct crypt
{
    char *op1;
    char *op2;
    char *res;
    char order[10];
    int value[10];
    int size;
    int set;
};
typedef struct crypt crypt;

int max3(int a, int b, int c)
{
    if (a > b && a > c)
    {
        return a;
    }
    if (b > c)
    {
        return b;
    }
    return c;
}

bool is_in(char elt, char tab[], int tsize)
{
    for (int i = 0; i < tsize; i++)
    {
        if (tab[i] == elt)
        {
            return true;
        }
    }
    return false;
}

int get_value(crypt mc, char c)
{
    for (int i = 0; i < mc.size; i++)
    {
        if (mc.order[i] == c)
        {
            return mc.value[i];
        }
    }
    return -2;
}

char *get_order(crypt mc)
{
    int sop1 = strlen(mc.op1);
    int sop2 = strlen(mc.op2);
    int sres = strlen(mc.res);
    char *order = malloc(sizeof(char) * 10);
    int size = max3(sop1, sop2, sres);
    int idx = 0;
    for (int i = 0; i < size; i++)
    {
        if (sop1 - i - 1 >= 0 && !(is_in(mc.op1[sop1 - i - 1], order, idx)))
        {
            order[idx] = mc.op1[sop1 - i - 1];
            idx++;
        }
        if (sop2 - i - 1 >= 0 && !(is_in(mc.op2[sop2 - i - 1], order, idx)))
        {
            order[idx] = mc.op2[sop2 - i - 1];
            idx++;
        }
        if (sres - i - 1 >= 0 && !(is_in(mc.res[sres - i - 1], order, idx)))
        {
            order[idx] = mc.res[sres - i - 1];
            idx++;
        }
    }
    return order;
}

crypt make_crypt(char *op1, char *op2, char *r)
{
    crypt mc;
    mc.op1 = malloc(sizeof(char) * strlen(op1));
    mc.op2 = malloc(sizeof(char) * strlen(op2));
    mc.res = malloc(sizeof(char) * strlen(r));
    strcpy(mc.op1, op1);
    strcpy(mc.op2, op2);
    strcpy(mc.res, r);
    strcpy(mc.order, get_order(mc));
    for (unsigned int i = 0; i < 10; i++)
    {
        mc.value[i] = -1;
    }
    mc.size = strlen(mc.order);
    mc.set = 0;
    return mc;
}

bool uniques(int tab[], int size)
{
    bool seen[size];
    for (int i = 0; i < size; i++)
    {
        seen[i] = false;
    }
    for (int i = 0; i < size; i++)
    {
        if (tab[i] != -1)
        {
            if (seen[tab[i]])
            {
                return false;
            }
            else
            {
                seen[tab[i]] = true;
            }
        }
    }
    return true;
}

bool is_valid(crypt mc)
{
    int sop1 = strlen(mc.op1);
    int sop2 = strlen(mc.op2);
    int sres = strlen(mc.res);
    int size = max3(sop1, sop2, sres);
    int c1, c2, r;
    int cr = 0;
    if (!uniques(mc.value, 10))
    {
        return false;
    }
    for (int i = 0; i < size; i++)
    {
        if (sop1 - i - 1 >= 0)
        {
            c1 = get_value(mc, mc.op1[sop1 - i - 1]);
        }
        else {c1=0;}
        if (sop2 - i - 1 >= 0)
        {
            c2 = get_value(mc, mc.op2[sop2 - i - 1]);
        }
        else {c2=0;}
        if (sres - i - 1 >= 0)
        {
            r = get_value(mc, mc.res[sres - i - 1]);
        }
        else {r=0;}
        if (c1 != -1 && c2 != -1 && r != -1)
        {
            if ((c1 + c2 + cr) % 10 != r)
            {
                return false;
            }
            else
            {
                cr = (c1 + c2 + cr) / 10;
            }
        }
        
    }
    return true;
}

char pchar(crypt mc, char c)
{
    if (get_value(mc, c) == -1)
    {
        return c;
    }
    else
    {
        return '0' + get_value(mc, c);
    }
}

void show_crypt(crypt mc)
{
    for (unsigned int i = 0; i < strlen(mc.op1); i++)
    {
        printf("%c", pchar(mc, mc.op1[i]));
    }
    printf(" + ");
    for (unsigned int i = 0; i < strlen(mc.op2); i++)
    {
        printf("%c", pchar(mc, mc.op2[i]));
    }
    printf(" = ");
    for (unsigned int i = 0; i < strlen(mc.res); i++)
    {
        printf("%c", pchar(mc, mc.res[i]));
    }
    printf("\n");
}

bool solve(crypt *mc, int idx)
{
    if (mc->size == idx)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            mc->value[idx] = i;
            if (is_valid(*mc) && solve(mc, idx + 1))
            {
                return true;
            }
        }
        mc->value[idx] = -1;
        return false;
    }
}
int main()
{
    crypt mc = make_crypt("SEND", "MORE", "MONEY");
    show_crypt(mc);
    solve(&mc, 0);
    show_crypt(mc);
}