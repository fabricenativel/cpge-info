# include <stdio.h>
# include <string.h>

void retourne(char str[])
{
    int n = strlen(str);
    for (int i=n;i>=0;i--) printf("%c",str[i]);
    printf("\n");
}

int main()
{
    retourne("Bonjour");
}
