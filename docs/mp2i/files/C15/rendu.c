#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define INF INT32_MAX

int min_pieces(int s, int pieces[], int k)
{
    int m1, m2;
    if (s == 0)
    {
        return 0;
    }
    if (k == 0)
    {
        return INF;
    }
    if (s < pieces[k])
    {
        return min_pieces(s, pieces, k - 1);
    }
    m1 = 1 + min_pieces(s - pieces[k], pieces, k);
    m2 = min_pieces(s, pieces, k - 1);
    if (m1 < m2)
    {
        return m1;
    }
    else
    {
        return m2;
    }
}

int min_iter(int s, int pieces[], int k)
{
    int memo[s + 1][k + 1];
    int r;
    for (int i = 0; i <= k; i++)
    {
        memo[0][i] = 0;
    }
    for (int i = 1; i <= s; i++)
    {
        memo[i][0] = INF;
    }
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i < pieces[j])
            {
                memo[i][j] = memo[i][j - 1];
            }
            else
            {
                if (memo[i - pieces[j]][j] + 1 < memo[i][j - 1])
                {
                    memo[i][j] = memo[i - pieces[j]][j] + 1;
                }
                else
                {
                    memo[i][j] = memo[i][j - 1];
                }
            }
        }
    }
    for (int i=0;i<=s;i++)
    {
        for (int j=0;j<=k;j++)
        {
            if (memo[i][j]==INF) printf("& x "); else printf("& %d ",memo[i][j]);
        }
        printf("\\\\ \n");
    }
    r = memo[s][k];
    return r;
}

int main()
{
    int pieces[] = {0, 1, 3, 4, 5};
    int nb = 4;
    int s = 7;
    int r1 = min_pieces(s, pieces, nb);
    int r2 = min_iter(s, pieces, nb);
    printf("Nombre minimal (récursif) = %d\n", r1);
    printf("Nombre minimal (itératif) = %d\n", r2);
}
