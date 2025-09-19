#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

struct number_s
{
    uint8_t *digits;
    uint64_t size;
};
typedef struct number_s number;

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

number next(number dn)
{
    number nn;
    nn.size = dn.size + 1;
    nn.digits = malloc(sizeof(uint8_t) * nn.size);
    uint8_t carry = 0;
    for (uint64_t i = 0; i < dn.size; i++)
    {
        nn.digits[i] = dn.digits[i] + dn.digits[dn.size - 1 - i] + carry;
        if (nn.digits[i] >= 10)
        {
            nn.digits[i] -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }
    if (carry == 1)
    {
        nn.digits[nn.size - 1] = carry;
    }
    else
    {
        nn.size--;
    }
    return nn;
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

uint64_t lychrel(number dn)
{
    number nn;
    uint64_t niter = 0;
    clock_t start = clock();
    while (!palindrome(dn))
    {

        if (niter % 100000 == 0)
        {
            printf("%ld itérations - nombre a %ld chiffres en %lf sec \n", niter, dn.size,(double)(clock()-start)/CLOCKS_PER_SEC);

            start = clock();
        }
        nn = next(dn);
        destroy(dn);
        dn = nn;
        niter++;
    }
    destroy(nn);
    return niter;
}


uint64_t reach(number dn, uint64_t limit, uint64_t step)
{
    uint64_t niter = 0;
    clock_t start = clock();
    uint8_t *old;
    while (dn.size != limit)
    {
        if (dn.size%step == 0)
        {
            printf("Nombre à %ld chiffres atteint après %ld itérations en %lf sec \n", dn.size, niter,(double)(clock()-start)/CLOCKS_PER_SEC);
        }
        old = dn.digits;
        dn = next(dn);
        free(old);
        niter++;
    }
    return niter;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Utilisation : %s <entier>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    number dn = create(atoi(argv[1]));
    uint64_t niter = reach(dn, 1000000, 10000);
    printf("Terminé après %ld itérations !\n",niter);
}
