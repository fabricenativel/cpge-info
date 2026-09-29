#include <stdio.h>
int main()
{
	int tab[5] = {42};
	int i = 0;
	while (i < 6)
	{
		printf("%d \n", tab[i]);
		i = i + 1;
	}
}