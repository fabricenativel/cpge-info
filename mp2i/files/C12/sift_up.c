bool insert_heap(int nv, heap *mh)
{
    int cp = mh->size;
    if (mh->size == mh->capacity)
    {
        return false;
    }
    else
    {
        mh->array[cp] = nv;
        while (father(cp) != -1 && mh->array[cp] < mh->array[father(cp)])
        {
            swap(mh->array, cp, father(cp));
            cp = father(cp);
        }
        mh->size = mh->size + 1;
        return true;
    }
}
