#include <stdio.h>

int n = 42;

void incremente(int n)
{ 
	n = n + 1;
	printf("Valeur de n dans la fonction = %d\n",n)
}

int main()
{
	incremente(n);
	printf(" Valeur de n = %d\n",n);
}