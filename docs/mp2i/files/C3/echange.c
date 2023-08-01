void echange(int *p1, int *p2) 
{
    int v1 = *p1;
    int v2 = *p2;
    int temp = v1;
    *p1 = v2;
    *p2 = temp;
}
