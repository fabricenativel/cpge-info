#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void view(char* str, int d, int f)
{
    for (int i=d; i<=f;i++)
    {
        printf("%c",str[i]);
    }
}

void lps(char *str, int *s, int *e)
{
    // str[s:e] : plus longue sous chaine palindrome
    int n = strlen(str);
    bool **ispal = malloc(sizeof(bool*) * n);
    int maxl = 0;
    for (int i = 0; i < n; i++)
    {
        ispal[i] = malloc(sizeof(bool) * n);
    }
    // ispal[i][j] vaut true si s[i]..s[j] est un palindrome
    for (int i = 0; i < n; i++) 
    {
        ispal[i][i] = true; //Traite les sous chaines de taille 1
    }
    for (int i=0;i<n-1;i++)
    {
        ispal[i][i+1] = (str[i]==str[i+1]); //Traite les sous chaines de taille 2
    }
    // Chaine de longueur > 2
    for (int s = 2; s < n; s++)
    {
        for (int i = 0; i < n-s; i++)
        {
            ispal[i][i+s] = (str[i]==str[i+s] && ispal[i+1][i+s-1]);   
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {
            if (ispal[i][j] && (j-i+1>maxl))
            {
                maxl=j-i+1;
                *s = i;
                *e = j;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        free(ispal[i]);
    }
    free(ispal);
    
}

int main()
{
    char test[] = "babad";
    int deb, fin;
    lps(test,&deb,&fin);
    printf("LPS = ");
    view(test,deb,fin);
    printf("\n");
}