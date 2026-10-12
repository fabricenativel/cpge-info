#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct config_s
{
    int size;
    bool *cells;
};
typedef struct config_s config;

config init(int size, bool state)
{
    config c;
    c.size = size;
    c.cells = malloc(sizeof(bool) * size);
    for (int i = 0; i < size; i++)
    {
        c.cells[i] = state;
    }
    return c;
}

bool rule90(bool prev, bool current, bool next)
{
    if ((!prev && !current && !next) || (!prev && current && !next) || (prev && !current && next) || (prev && current && next))
    {
        return false;
    }
    return true;
}

bool rule(bool prev, bool current, bool next, int rnumber)
{
    int cvalue = 0;
    if (next)
    {
        cvalue += 1;
    }
    if (current)
    {
        cvalue += 2;
    }
    if (prev)
    {
        cvalue += 4;
    }
    return ((rnumber >> cvalue & 1) == 1);
}

void evolution(config *c)
{
    bool prev, current, next;
    bool *newcells = malloc(sizeof(bool) * c->size);
    for (int i = 0; i < c->size; i++)
    {
        current = c->cells[i];
        prev = i == 0 ? false : c->cells[i - 1];
        next = i == c->size - 1 ? false : c->cells[i + 1];
        newcells[i] = rule(prev, current, next, 60);
    }
    free(c->cells);
    c->cells = newcells;
}

int alive(config c)
{
    int a = 0;
    for (int i = 0; i < c.size; i++)
    {
        if (c.cells[i])
        {
            a++;
        }
    }
    return a;
}

void display(config c)
{
    for (int i = 0; i < c.size; i++)
    {
        if (c.cells[i])
        {
            printf("#");
        }
        else
        {
            printf(".");
        }
    }
    printf("\n");
}

void destroy(config *c)
{
    c->size = 0;
    free(c->cells);
}

int main()
{
    config c = init(500, false);
    c.cells[1] = true;
    for (int i = 0; i < 500; i++)
    {
        //display(c);
        evolution(&c);
    }
    printf("Résultat = %d \n", alive(c));
    destroy(&c);
    return 0;
}
