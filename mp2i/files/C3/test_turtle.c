#include "turtle.h"

int main()
{
    /* crée une image de taille 300x300
      le centre de l'image est le point (0,0)
      la tortue y est positionnée */
    turtle_init(300, 300);          
    /* dessin d'un carré de coté 100
     on avance de 100 et on tourne de 90°
     à 4 reprises
    */
    for (int i=0;i<4;i++)
    {
    turtle_forward(100);
    turtle_turn_left(90);
    }
    // Sauve l'image pour la visualiser
    turtle_save_bmp("carre.bmp");
    return 0;
}