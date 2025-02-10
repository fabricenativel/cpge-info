bool insert_heap(int nv, heap *mh)
{
    int cp = mh->size;
    if (mh->size == mh->capacity)
    {
        return false;
    }
    else
    {
        mh->tab[cp] = nv;
        while (father(cp) != -1 && mh->tab[cp] < mh->tab[father(cp)])
        {
            swap(mh->tab, cp, father(cp));
            cp = father(cp);
        }
        mh->size = mh->size + 1;
    }
}
