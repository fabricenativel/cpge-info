#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int randint(int vmin, int vmax)
{
    return rand()%(vmax-vmin+1) + vmin;
}

// Crée un fichier de n entiers choisis au hasard entre vmin et vmax (inclus)
void make_file(int n, int vmin, int vmax, char filename[])
{
    FILE * writer = fopen(filename,"w");
    int nrand;
    for (int i=0;i<n;i++)
    {   
        nrand = randint(vmin,vmax);
        fprintf(writer,"%d\n",nrand);
    }
    fclose(writer);
}

int main(int argc,char  *argv[])
{
    srand(time(NULL));
    if (argc!=5) {printf("Utilisation : ./write_int nb_entiers vmin vmax filename\n");}
    else
    { make_file(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),argv[4]);}
}