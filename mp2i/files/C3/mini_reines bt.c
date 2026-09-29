#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

struct config_s
{
    int size;       // Taille échiquier
    int threatened; // Nombre cases menacées
    int *board;     // Etat du plateau : -1 : contient une reine sinon nombres de reines menacant la case
};
typedef struct config_s config;

config init_config(int n)
{
    config new;
    new.size = n;
    new.threatened = 0;
    new.board = malloc(sizeof(state) * n * n);
    for (int i = 0; i < n * n; i++)
    {
        new.board[i] = 0;
    }
    return new;
}

bool *get_threat(int l, int c, int n)
{
    // Pour un échiquier nxn renvoie le tableau de booléens indiquant les cases menacées par une reine en (l,c)
    bool *threat = malloc(sizeof(bool) * n * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            threat[i * n + j] = false;
            if (i == l || j == c || abs(l - i) == abs(c - j))
            {
                threat[i * n + j] = true;
            }
        }
    }
    return threat;
}

bool **cover(int n)
{
    bool **covered = malloc(sizeof(bool *) * n * n);
    for (int l = 0; l < n; l++)
    {
        for (int c = 0; c < n; c++)
        {
            covered[l * n + c] = get_threat(l, c, n);
        }
    }
    return covered;
}

void set_queen(config *conf, int l, int c, bool **threat)
{
    int n = conf->size;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (threat[l * n + c][i * n + j] && conf->board[i * n + j] != -1)
            {
                conf->board[i * n + j]++;
                if (conf->board[i * n + j] == 1)
                {
                    conf->threatened++;
                }
            }
        }
    }
    conf->board[l * n + c] = -1;
}

config greedy(int n)
{
    config conf = init_config(n);
    bool **all_cover = cover(n);
    int max_num, max_l, max_c;
    int current;
    while (conf.threatened != n * n)
    {
        max_num = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                current = newly_covered(conf, all_cover, i, j);
                {
                    if (current > max_num)
                    {
                        max_num = current;
                        max_l = i;
                        max_c = j;
                    }
                }
            }
        }
        printf("Reine placée en (%d,%d) - %d cases nouvellement menacées \n", max_l, max_c, max_num);
        set_queen(&conf, max_l, max_c, all_cover);
    }
    return conf;
}

void view_config(config conf)
{
    int n = conf.size;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            switch (conf.board[i * n + j])
            {
            case QUEEN:
                printf("Q");
                break;
            case FREE:
                printf("#");
                break;
            case COVERED:
                printf(".");
                break;
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Utilisation : %s <taille echiquier> \n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int n = atoi(argv[1]);
    config sol = greedy(n);
    view_config(sol);
    return 0;
}