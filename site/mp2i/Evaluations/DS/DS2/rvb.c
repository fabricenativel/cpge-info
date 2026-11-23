#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct couleur_s
{
    uint8_t r;
    uint8_t v;
    uint8_t b;
};
typedef struct couleur_s couleur;

couleur negatif(couleur c)
{
    couleur negatif;
    negatif.r = 255 - c.r;
    negatif.v = 255 - c.v;
    negatif.b = 255 - c.b;
    return negatif;
}

void transforme_negatif(couleur *c)
{
    c->r = 255 - c->r;
    c->v = 255 - c->v;
    c->b = 255 - c->b;
}

uint8_t ajoute_plafonne(uint8_t val, uint8_t delta)
{
    if (val > 255 - delta)
    {
        return 255;
    }
    return val + delta;
}

couleur melanger(couleur c1, couleur c2)
{
    couleur m;
    uint8_t sr = c1.r + c2.r;
    uint8_t sv = c1.v + c2.v;
    uint8_t sb = c1.b + c2.b;
    m.r = sr / 2;
    m.v = sv / 2;
    m.b = sb / 2;
    return m;
}

couleur melanger_corrige(couleur c1, couleur c2)
{
    couleur m;
    m.r = (c1.r / 2) + (c2.r / 2);
    m.v = (c1.v / 2) + (c2.v / 2);
    m.b = (c1.b / 2) + (c2.b / 2);
    return m;
}

couleur* palette(int n)
{
    couleur *palette = malloc(sizeof(couleur) * n);
    for (int i = 0; i < n; i++)
    {
        palette[i].r = rand() % 256;
        palette[i].v = rand() % 256;
        palette[i].b = rand() % 256;
    }
    return palette;
}

int longueur(char *s)
{
    int l = 0;
    while (s[l] != '\0')
    {
        l++;
    }
    return l;
}

int valeur_hexa(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
}

bool depuis_hexa(char *chaine, couleur *res)
{
    if (longueur(chaine) != 7 || chaine[0] != '#')
    {
        return false;
    }
    int chiffres[6];
    for (int i = 0; i < 6; i++)
    {
        chiffres[i] = valeur_hexa(chaine[i + 1]);
        if (chiffres[i] == -1)
        {
            return false;
        }
    }
    res->r = 16 * chiffres[0] + chiffres[1];
    res->v = 16 * chiffres[2] + chiffres[3];
    res->b = 16 * chiffres[4] + chiffres[5];
    return true;
}

void affiche_couleur(couleur c)
{
    printf("RVB(%hhu, %hhu, %hhu) - #%02X%02X%02X\n", c.r, c.v, c.b, c.r, c.v, c.b);
}

int main()
{
    couleur c = {.r = 25, .v = 200, .b = 12};
    affiche_couleur(c);
    transforme_negatif(&c);
    affiche_couleur(c);
    couleur *pal = palette(10);
    free(pal);
    couleur c_hex;
    if (depuis_hexa("#3A80FF", &c_hex))
    {
        affiche_couleur(c_hex);
    }
    return EXIT_SUCCESS;
}
