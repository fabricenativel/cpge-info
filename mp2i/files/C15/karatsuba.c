#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE = 32

int *tab_from_str(char *s)
{
    int n = strlen(s);
    int *res = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        res[i] = s[i] - 48;
    }
    return res;
}

char *str_from_tab(int *tab, int size)
{
    char *str = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < size; i++)
    {
        str[i] = tab[i] + 48;
    }
    str[size] = '\0';
    return str;
}

int *decale(int *a, int t, int d)
{
    int *res = malloc(sizeof(int) * (t + d));
    for (int i = 0; i < t + d; i++)
    {
        if (i > t)
        {
            res[i] = 0;
        }
        else
        {
            res[i] = a[i];
        }
    }
    return res;
}

int *somme(int *t1, int *t2, int t)
{
    int *res = malloc(sizeof(int) * (t + 1));
    int ret = 0;
    for (int i = t - 1; i >= 0; i--)
    {
        res[i+1] = (t1[i] + t2[i] + ret) % 10;
        if (t1[i] + t2[i] + ret > 9)
        {
            ret = 1;
        }
        else
        {
            ret = 0;
        }
    }
    res[0] = ret;
    return res;
}

int *mult(int *a, int *b, int t)
{
    int *res = malloc(sizeof(int) * t * 2);
    if (t == 1)
    {   
        res[0] = (a[0] * b[0]) / 10;
        res[1] = (a[0] * b[0]) % 10;
    }
    else
    {
        t = t / 2;
        int *a1 = a;
        int *a2 = a + t;
        int *b1 = b;
        int *b2 = b + t;
        int *res11 = decale(mult(a1, b1, t),2*t,2*t);
        int *res12 = decale(mult(a1, b2, t),2*t,t);
        int *res21 = decale(mult(a2, b1, t),2*t,t);
        int *res22 = mult(a2, b2, t);
        printf("r11 = %s\n",str_from_tab(res11,4*t));
        printf("r12 = %s\n",str_from_tab(res12,3*t));
        printf("r21 = %s\n",str_from_tab(res21,3*t));
        printf("r22 = %s\n",str_from_tab(res22,2*t));
        int *sp1 = somme(res11,res12,4*t);
        printf("sp1 = %s\n",str_from_tab(sp1,4*t));
        int *sp2 = somme(sp1,res21,4*t);
        int *res = somme(sp2,res22,4*t);
    }
    return res;
}

int main()
{
    int *test1 = tab_from_str("99");
    int *test2 = tab_from_str("99");
    printf("Résultat = %s\n", str_from_tab(mult(test1,test2,2),4));
}