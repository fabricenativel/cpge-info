#include <stdio.h>
#include <stdbool.h>

const int COL_START[7] = {2, 1, 0, 0, 0, 1, 2};
const int COL_END[7] = {4, 5, 6, 6, 6, 5, 4};
const int ML[4] = {0, -1, 0, 1};
const int MC[4] = {1, 0, -1, 0};

// Un mouvement représenté comme les coordonnées d'un pion et la direction
struct move_s
{
    int sl;
    int sc;
    int dir;
};
typedef struct move_s move;

struct jeu_s
{
    bool plateau[7][7];
    int pierres;
};
typedef struct jeu_s jeu;

bool ingrid(int l, int c)
{
    return (l >= 0 && l < 7 && c >= COL_START[l] && c <= COL_END[l]);
}

jeu cree_jeu(int l, int c)
{
    jeu tj;
    tj.pierres = 0;
    for (int i=0;i<7;i++)
    {
        for (int j=COL_START[i];j<=COL_END[i];j++)
        {
            tj.plateau[i][j]=true;
            tj.pierres++;
        }
    }
    tj.plateau[l][c] = false;
    tj.pierres--;
    return tj;
}

void display(jeu tj)
{   
    printf("Nombre de pierres : %d\n",tj.pierres);
    for (int i=0;i<7;i++)
    {
        for (int j=0;j<7;j++)
        {
            if (j<COL_START[i] || j>COL_END[i])
            {
                printf(" ");
            }
            else
            {
                if (tj.plateau[i][j])
                {
                    printf("x");
                }
                else
                {
                    printf(".");
                }
            }
        }
        printf("\n");
    }
}

bool solve(jeu* lejeu)
{
    //display(*lejeu);
    //char c = getc(stdin);
    if (lejeu->pierres == 1)
    {
        return true;
    }
    // Recherche des mouvements
    for (int lig = 0; lig < 7; lig++)
    {
        for (int col = COL_START[lig]; col < COL_END[lig]; col++)
        {
            if (lejeu->plateau[lig][col])
            {
                for (int k = 0; k < 4; k++)
                {
                    if (ingrid(lig + 2*ML[k], col + 2*MC[k]) && lejeu->plateau[lig + ML[k]][col + MC[k]]  && !lejeu->plateau[lig + 2 * ML[k]][col + 2 * MC[k]])
                    {
                        // Faire le mouvement
                        lejeu->plateau[lig][col]=false;
                        lejeu->plateau[lig+ML[k]][col+MC[k]]=false;
                        lejeu->plateau[lig+2*ML[k]][col+2*MC[k]]=true;
                        lejeu->pierres--;
                        if (!solve(lejeu))
                        {
                            lejeu->plateau[lig][col]=true;
                            lejeu->plateau[lig+ML[k]][col+MC[k]]=true;
                            lejeu->plateau[lig+2*ML[k]][col+2*MC[k]]=false;
                            lejeu->pierres++;
                        }
                        else
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    jeu test = cree_jeu(2,2);
    solve(&test);

}