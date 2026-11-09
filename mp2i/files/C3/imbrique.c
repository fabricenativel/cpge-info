#include "turtle.h"

void carre(int taille)
{
  for (int i=0;i<4;i++)
    {
    turtle_forward(taille);
    turtle_turn_left(90);
    }
}

int main()
{
    turtle_init(400, 400);      
    for (int i=390;i>0;i=i-30){
    turtle_pen_up();
    turtle_goto(-i/2,-i/2);
    turtle_pen_down();
    carre(i);
    }
    turtle_save_bmp("imbrique.bmp");
    return 0;
}