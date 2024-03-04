#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 14
#define WHITE "white"
#define BLACK "black!30"
#define QUEEN "\\queen"

int nb_sol = 0;

void make_latex(int tab[], int size, char *filename)
{
    FILE *writer = fopen(filename, "w");
    fprintf(writer, "\\renewcommand{\\arraystretch}{1.5}\n \\begin{tabular}{|P{0.2cm}|P{0.2cm}|P{0.2cm}|P{0.2cm}|P{0.2cm}|P{0.2cm}|P{0.2cm}|P{0.2cm}|} \n \\hline");
    bool white = true;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (white)
            {
                fprintf(writer, "\\cellcolor{%s}", WHITE);
            }
            else
            {
                fprintf(writer, "\\cellcolor{%s}", BLACK);
            }
            white = !white;
            if (tab[i] == j)
            {
                fprintf(writer, "{\\queen}");
            }
            else
            {
                fprintf(writer, "{}");
            }
            if (j == size - 1)
            {
                fprintf(writer, "\\\\");
            }
            else
            {
                fprintf(writer, "&");
            }
        }
        white = !white;
        fprintf(writer, "%s", "\n \\hline \n");
    }
    fprintf(writer, "%s", "\\end{tabular} \n");
}

void affiche(int tab[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", tab[i]);
    }
    printf("\n");
}

bool menace(int tab[], int idx)
{
    for (int i = 0; i <= idx - 1; i++)
    {
        if (tab[i] == tab[idx] || abs(tab[i] - tab[idx]) == idx - i)
        {
            return true;
        }
    }
    return false;
}

void nqueens(int tab[], int index)
{
    if (index == SIZE)
    {
        nb_sol++;
        printf("%d) ->", nb_sol);
        affiche(tab, SIZE);
        if (nb_sol == 1)
        {
            make_latex(tab, SIZE, "sol1");
        }
    }
    else
    {
        for (int p = 0; p < SIZE; p++)
        {
            tab[index] = p;
            if (!menace(tab, index))
            {
                nqueens(tab, index + 1);
            }
        }
    }
}

bool solve(int sol[], int size, int idx)
{
    if (idx == size)
    {
        return true;
    }
    else
    {
        for (int p = 0; p < size; p++)
        {
            sol[idx] = p;
            if (!menace(sol, idx) && solve(sol, size, idx + 1))
            {
                return true;
            }
        }
        return false;
    }
}

void nreines(int sol[], int size, int index, int *nb_sol)
{
    if (index == size)
    {
        *nb_sol = *nb_sol+1;
    }
    else
    {
        for (int p = 0; p < SIZE; p++)
        {
            sol[index] = p;
            if (!menace(sol, index))
            {
                nreines(sol,size, index + 1,nb_sol);
            }
        }
    }
}

int main()
{
    int tab[SIZE] = {0};
    int n = 0;
    nreines(tab,SIZE,0,&n);
    printf("Problème des %d reines : %d solutions\n", SIZE, n);
    // nqueens(tab, 0);
    // printf("Problème des %d reines : %d solutions\n", SIZE, nb_sol);
}
