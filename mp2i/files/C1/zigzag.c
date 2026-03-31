#include <stdio.h>
#include <string.h>


void zigzag(char s[], int rows)
{
    int l = strlen(s);
    int cols = l;
    char to_print[rows][cols];
    int cl = 0;
    int cc = 0;
    int dl = 1;
    for (int r=0;r<rows;r++)
    {
        for (int c=0;c<cols;c++)
        {
            to_print[r][c] = ' ';
        }
    }
    for (int i=0;i<l;i++)
    {
        to_print[cl][cc] = s[i];
        if (cl==rows-1)
        {
            dl = -1;
        }
        if (cl==0)
        {
            dl = 1;
        }
        cl += dl;
        cc += 1;
    }
    for (int r=0;r<rows;r++)
    {
        for (int c=0;c<cols;c++)
        {
            printf("%c",to_print[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    char test[] = "BONNE RENTREE AUX MP2I !";
    zigzag(test,4);
}