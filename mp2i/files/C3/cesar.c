# include <stdio.h>

char chiffre(char car, int cle)
{
    char new_car = car;
    if (car>=65 && car<=90)
    {
        new_car = (car+cle-65)%26 + 65;
    }
    return new_car;
}

int main()
{
    char car;
    int cle;
    printf("Clé = ");
    scanf(" %d",&cle);
    printf("Caractère = ");
    scanf(" %c",&car);
    printf("Résultat = %c\n",chiffre(car,cle));

}