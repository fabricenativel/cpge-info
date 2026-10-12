#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define SIZE 100000

int* make_array(char filename[])
{
    int *nums = malloc(sizeof(int)*SIZE);
    FILE* reader = fopen(filename,"r");
    for (int i=0;i<SIZE;i++)
    {
        fscanf(reader,"%d\n",&nums[i]);
    }
    return nums;
}

bool is_in(int* nums, int val, int start)
{
    for (int i=start;i<SIZE;i++)
    {
        if (nums[i]==val)
        {return true;}

    }
    return false;
}

int getsol(int *nums)
{
    for (int i=0;i<SIZE-1;i++)
    {
        if (is_in(nums,42-nums[i],i+1))
        {
            return nums[i];
        }
    }
    return 0;
}

int main()
{
    int * nums = make_array("numbers.txt");
    int sol;
    sol = getsol(nums);
    printf("Solution : (%d,%d)\n",sol,42-sol);
    free(nums);
}