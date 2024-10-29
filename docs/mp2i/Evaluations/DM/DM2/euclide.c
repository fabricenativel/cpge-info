#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// --8<-- [start:Q6]
struct fraction_s
{
    int num;
    int den;
};
typedef struct fraction_s fraction;
// --8<-- [end:Q6]



// --8<-- [start:Q3]
int pgcd(int a, int b)
{
    assert(a >= 0 && b >= 0);
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
// --8<-- [end:Q3]

// --8<-- [start:Q5]
int pgcd_recursif(int a, int b)
{
    assert(a >= 0 && b >= 0);
    if (b==0)
    {return a;}
    return pgcd_recursif(b,a%b);
}
// --8<-- [end:Q5]

// --8<-- [start:Q7]
void simplifie(fraction *f)
{
    int d = pgcd(f->num,f->den);
    f->num = f->num / d;
    f->den = f->den / d;
}
// --8<-- [end:Q7]


// --8<-- [start:Q8]
fraction addition(fraction f, fraction g)
{
    fraction h;
    h.den = f.den*g.den/pgcd(f.den,g.den);
    h.num = f.num * (h.den/f.den) + g.num * (h.den/g.den);
    return h;
}
// --8<-- [end:Q8]

void affiche(fraction f)
{
    printf("%d/%d",f.num,f.den);
}

int main()
{
    fraction f = {.num = 1, .den =7};
    fraction g = {.num = 1, .den = 5};
    fraction h = addition(f,g);
    affiche(h);
    printf("\n");
}