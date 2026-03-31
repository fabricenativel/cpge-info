#include <stdio.h>
#include <assert.h>

int nb_chiffres(int n)
{
    assert (n>=0); 
    if (n==0) {return 1;}
    int c = 0;
    while (n!=0)
    {
        c = c + 1;
        n = n / 10; 
    }
    return c;
}

void test_nb_chiffres()
{
    assert(nb_chiffres(0) == 1);
    assert(nb_chiffres(5) == 1);
    assert(nb_chiffres(1942) == 4);
    assert(nb_chiffres(99999) == 5);
    assert(nb_chiffres(100000) == 6);
}

int main()
{
    test_nb_chiffres();
    printf("Tous les tests ont réussi.\n");
    return 0;
}