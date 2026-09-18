#include <stdio.h>
#include <stdlib.h>

#define TMAX 100

struct stab_s
{
    int *val;
};
typedef struct stab_s stab;

void view_size(stab st)
{
    int s = sizeof(st.val)/sizeof(int);
    printf("Taille : %d\n", s);
}

void change(stab st)
{
    st.val[0] = 55;
}

int main()
{
    stab t;
    t.val = malloc(sizeof(int)*TMAX);
    view_size(t);
    t.val[0] = 42;
    change(t);
    printf("En 0 : %d\n",t.val[0]);
    free(t.val);
    return 0;
}