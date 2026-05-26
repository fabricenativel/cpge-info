#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// --8<-- [start:struct]
struct number_s
{
    uint8_t *digits; // pointeur vers le tableau des chiffres
    uint64_t size;   // nombre de chiffres
};
typedef struct number_s number;
// --8<-- [end:struct]

number create(int n)
{
    number dn;
    dn.size = 0;
    int m = n;
    int i = 0;
    while (m != 0)
    {
        dn.size += 1;
        m /= 10;
    }
    dn.digits = malloc(sizeof(uint8_t) * dn.size);
    while (n != 0)
    {
        dn.digits[i++] = n % 10;
        n = n / 10;
    }
    return dn;
}

void view(number dn)
{
    for (int i = dn.size - 1; i >= 0; i--)
    {
        printf("%u", dn.digits[i]);
    }
    printf("\n");
}

void next(number *dn)
{
    uint8_t *newdigits = malloc(sizeof(uint8_t) * (dn->size+1));
    uint8_t carry = 0;
    for (uint64_t i = 0; i < dn->size; i++)
    {
        newdigits[i] = dn->digits[i] + dn->digits[dn->size - 1 - i] + carry;
        if (newdigits[i] >= 10)
        {
            newdigits[i] -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }
    if (carry == 1)
    {
        newdigits[dn->size] = 1;
        dn->size ++;
    }
    free(dn->digits);
    dn->digits = newdigits;
}

bool palindrome(number dn)
{
    for (uint64_t i = 0; i < dn.size / 2; i++)
    {
        if (dn.digits[i] != dn.digits[dn.size - 1 - i])
        {
            return false;
        }
    }
    return true;
}

void destroy(number dn)
{
    free(dn.digits);
}

int lychrel(number *dn, int limit)
{
    int niter = 0;
    while (!palindrome(*dn) && niter < limit)
    {
        next(dn);
        niter++;
    }
    if (!palindrome(*dn))
    {
        return -1;
    }
    return niter;
}

bool walker(number *dn, uint64_t limit, int* nb_iter)
{
    *nb_iter = 0;
    while (!palindrome(*dn) && dn->size < limit)
    {
        next(dn);
        *nb_iter = *nb_iter + 1;
        if (dn->size%50000==0)
        {
            printf("%ld chiffres\n",dn->size);
        }
    }
    if (!palindrome(*dn))
    {
        return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Utilisation : %s <entier>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    number dn = create(atoi(argv[1]));
    int limit = 1000000;
    int nb_iter;
    bool res = walker(&dn, limit, &nb_iter);
    if (res)
    {
        printf("Palindrome atteint ! Le nombre a %lu chiffres \n",dn.size);
    }
    else
    {
        printf("Palindrome non atteint après %d itétations \n",nb_iter);
        printf("Le nombre a %lu chiffres \n",dn.size);
    }
    destroy(dn);
}
