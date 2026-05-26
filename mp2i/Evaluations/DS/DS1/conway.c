#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000000

char* next(char *current)
{
    int lc = strlen(current);
    int pos = 0;
    int ln = 0;
    char * ns = malloc(sizeof(char) * 1000000);
    while (pos+2<lc)
    {
        ns[ln+1] = current[pos];
        if (current[pos]==current[pos+1] && current[pos]==current[pos+2])
        {
            pos += 3;
            ns[ln] = '3';
            
        }
        else if (current[pos]==current[pos+1])
        {
            pos += 2;
            ns[ln] = '2';
        }
        else 
        {
            pos += 1;
            ns[ln] = '1';
        }
        ln += 2;
    }
    if (pos == lc-2 && current[pos]==current[pos+1])
    {
        ns[ln] = '2';
        ns[ln+1] = current[pos];
        ln += 2;
    }
    else if (pos == lc-2)
    {
        ns[ln] = '1';
        ns[ln+1] = current[pos];
        ns[ln+2] = '1';
        ns[ln+3] = current[pos+1];
        ln += 4;
    }
    else if (pos == lc-1)
    {
        ns[ln] = '1';
        ns[ln+1] = current[pos];
        ln += 2;
    }
    ns[ln] = '\0';
    char * vs =  malloc(sizeof(char) * (ln + 1));
    strcpy(vs, ns);
    free(ns);
    return vs;
}

int main()
{
    char *current = malloc(sizeof(char) * 2);
    strcpy(current, "1");
    char *nt;
    printf("%s\n", current);
    for (int i=0;i<10;i++)
    {
        nt = next(current);
        printf("%s\n", nt);
        current = nt;
    }
    free(current);
    printf("Done.\n");
    return 0;
}