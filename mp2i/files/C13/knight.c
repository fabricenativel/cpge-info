#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 8

struct position
{
    int row;
    int col;
};
typedef struct position position;

struct lpos
{
    int n;
    position poss[8];
};
typedef struct lpos lpos;

struct solution
{
    position start;
    int path[SIZE][SIZE];
    int pathlen;
};
typedef struct solution solution;

bool ingrid(position p)
{
    return (p.row>=0 && p.row<SIZE && p.col>=0 && p.col<SIZE);
}


void view(solution s)
{
    for (int r=0;r<SIZE;r++)
    {
        for (int c=0;c<SIZE;c++)
        {
            if (s.path[r][c]==0)
            {
                printf(" . ");
            }
            else
            {
                if (s.path[r][c]<10)
                {
                    printf(" %d ",s.path[r][c]);
                }
                else
                {
                    printf("%d ",s.path[r][c]);
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

lpos getpos(solution s)
{
    int mx[8] = {-2,-2,-1,-1, 1, 1, 2, 2};
    int my[8] = {-1, 1,-2, 2,-2, 2,-1, 1};
    position cpos;
    lpos res;
    res.n = 0;
    for (int i=0;i<8;i++)
    {
        cpos.row = s.start.row + mx[i];
        cpos.col = s.start.col + my[i];
        if (ingrid(cpos) && s.path[cpos.row][cpos.col]==0)
        {
            res.poss[res.n++]=cpos;
        }
    }
    return res;
}

bool search(solution *s)
{   
    lpos possibilites;
    position old = s->start;
    //view(*s);
    if (s->pathlen<SIZE*SIZE)
    {
        possibilites = getpos(*s);
        for (int i=0;i<possibilites.n;i++)
        {
            s->pathlen++;
            s->path[possibilites.poss[i].row][possibilites.poss[i].col]=s->pathlen;
            s->start = possibilites.poss[i];
            if (search(s))
            { return true;}
            else
            {s->pathlen--;
            s->path[possibilites.poss[i].row][possibilites.poss[i].col]=0;
            s->start = old;}
        }
        return false;
    }
    else
    {
        return true;
    }
}


int main(int argc, char* argv[])
{
    solution s;
    for (int r=0;r<SIZE;r++)
    {
        for (int c=0;c<SIZE;c++)
        {
            s.path[r][c]=0;
        }
    }
    if (argc ==3){
    s.start.row = atoi(argv[1]);
    s.start.col= atoi(argv[2]);
    s.path[s.start.row][s.start.col] = 1;
    s.pathlen = 1;
    if (search(&s))
    {view(s);};}
    else
    {
        printf("Entrer la ligne et la position de départ du cavalier !\n");
    }
}