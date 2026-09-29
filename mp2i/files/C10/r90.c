#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define DEAD '.'
#define ALIVE '#'

char evo_cell(char prev,  char next)
{
    if (prev != next)
    {
       return ALIVE; 
    }
    return DEAD;
}

void evo_config(char *config)
{
    int n = strlen(config);
    char* temp = malloc(sizeof(char)*n);
    temp[0] = config[0];
    temp[n-1] = config[n-1];
    for (int i=1;i <n-1;i++)
    {
        temp[i] = evo_cell(config[i-1],config[i+1]);
    }
    for (int i=0;i <n;i++)
    {
        config[i] = temp[i];
    }
    free(temp);
}

bool same(char *c, char* r, int n)
{
    for (int i=0;i<n;i++)
    {
        if (c[i]!=r[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n= 30;
    char* c = malloc(sizeof(char)*n);
    char* r = malloc(sizeof(char)*n);
    for (int i=0;i<n;i++)
    {
        c[i] = DEAD;
        r[i] = DEAD;
    }
    c[n/2] = ALIVE;
    r[n/2] = ALIVE;
    int step = 0;
    bool end = false;
    while (!end)
    {
        evo_config(c);
        if (same(r,c,n))
        {
            end = true;
        }
        step += 1;
    }
    printf("Cycle après %d étapes \n",step);
    free(c);
}