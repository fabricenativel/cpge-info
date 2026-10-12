#include <stdio.h>
#include <stdint.h>

int main()
{
    uint8_t m = 250;
    uint8_t n = 50;
    uint8_t p;
    uint8_t  q;
    p = (m + n) % 10 ; //Autopromotion de m et n en int, l'addition donne 300 qui module 10 donne 0
    q = m + n; // Autopromotion de m et n en int, l'addition donne 300 mais stocké dans un uint8_t, donc q = 44
    q = q % 10; // q = 44 % 10 = 4
    printf("p = %u\nq = %u\n", p, q);
    return 0;
}