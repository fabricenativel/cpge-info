#include <stdio.h>
#include <stdbool.h>

bool mystere(int n) {
	int d=2;
	while (d*d<=n)
	{	if (n%d==0)
			{return false;}
		d=d+1;}
	return true;
}

int main()
{
    int n;
    printf("n=");
    scanf("%d",&n);
    if (mystere(n))
    {printf("%d est premier",n);}
    else
    {printf("%d n'est pas premier\n",n);}
    return 0;
}
