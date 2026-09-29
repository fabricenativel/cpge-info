#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b) 
{
	if (a<b) 
	{return -1;}
	else if (a==b)
	{return 0;}
	else
	return 1;
}

int main(int argc, char *argv[])
{   
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    if (argc!=3) return 1;
    printf("%d\n",compare(a,b));
}