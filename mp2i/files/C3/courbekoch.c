#include "turtle.h"
#include <stdio.h>

void koch(int taille, int ordre)
{   
    if (ordre == 0)
    {
        turtle_forward(taille);
    }
    else
    {
        koch(taille/3,ordre-1);
        turtle_turn_left(60);
        koch(taille/3,ordre-1);
        turtle_turn_right(120);
        koch(taille/3,ordre-1);
        turtle_turn_left(60);
        koch(taille/3,ordre-1);
    }
}

int main()
{
    turtle_init(500, 200);
    turtle_pen_up();
    turtle_goto(-240,-80);
    turtle_pen_down();
    koch(600,5);
    turtle_save_bmp("koch.bmp");
    return 0;
}