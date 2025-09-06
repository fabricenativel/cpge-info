#include "serpent.h"


Serpent *creer_serpent(int x, int y, int dir)
{
    Maillon *m= malloc(sizeof(Maillon));
    m->suivant = NULL;
    m->x = x;
    m->y = y;
    Serpent *s = malloc(sizeof(Serpent));
    s->direction = dir;
    s->tete = m;
    s->queue = m; 
    return s;
}

extern int prochain_x(const Serpent *s)
{
    if (s->direction==RIGHT)
    {
        return s->tete->x+1;
    }
    if (s->direction==LEFT)
    {
        return s->tete->x-1;
    }
    return s->tete->x;
}

extern int prochain_y(const Serpent *s)
{
    if (s->direction==UP)
    {
        return s->tete->y-1;
    }
    if (s->direction==DOWN)
    {
        return s->tete->y+1;
    }
    return s->tete->y;
}

extern bool appartient(const Serpent *s, int x, int y)
{
    Maillon *current = s->queue;
    while (current!=NULL)
    {
        if (current->x==x && current->y==y)
        {
            return true;
        }
        current = current->suivant;
    }
    return false;
}

extern void avancer(Serpent *s)
{
    Maillon *new = malloc(sizeof(Maillon));
    new->x = prochain_x(s);
    new->y = prochain_y(s);
    new->suivant = NULL;
    s->tete->suivant = new;
    s->tete = new;
    Maillon *old = s->queue;
    s->queue = s->queue->suivant;
    free(old);
}

extern void grandir(Serpent *s)
{
    Maillon *new = malloc(sizeof(Maillon));
    new->x = prochain_x(s);
    new->y = prochain_y(s);
    new->suivant = NULL;
    s->tete->suivant = new;
    s->tete = new;
}

extern void place_serpent(const Serpent *s, Arena mat)
{
    Maillon *current = s->queue;
    while (current!=NULL)
    {
        mat[current->x][current->y] = SNAKE;
        current = current->suivant;
    }
}

extern void destroy_serpent(Serpent *s)
{
    Maillon *current = s->queue;
    Maillon *temp;
    while (current!=NULL)
    {
        temp = current;
        current = current->suivant;
        free(temp);
    }
}