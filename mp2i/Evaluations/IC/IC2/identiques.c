#include <stdio.h>
#include <string.h>
#include <assert.h>

int minimum(int a, int b)
{
    if (a<b)
    {
        return a;
    }
    return b;
}

int identiques(char s[], char t[])
{
    int l = minimum(strlen(s),strlen(t));
    int id = 0;
    for (int i=0; i<l; i++)
    {
        if (s[i]==t[i])
        {
            id = id + 1;
        }
    }
    return id;
}

int main()
{
    assert (identiques("Minimum", "Maximum")==5);
    assert (identiques("Minimum", "")==0);
    assert (identiques("", "Maximum")==0);
    assert (identiques("M", "M")==1);
}