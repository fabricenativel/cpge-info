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
    turtle_init(500, 500);      
    turtle_set_pen_color(50,50,150);
    for (int i=36;i>0;i--){
    carre(150);
    turtle_turn_left(10);
    }
    // Sauve l'image pour la visualiser
    turtle_save_bmp("carre2.bmp");  // save the turtle drawing
    return 0;
}