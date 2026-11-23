from random import randint

def qsort(lst):
    '''Trie la liste lst en utilisant l'algorithme du tri rapide'''
    def aux(deb, fin):
        '''Fontion auxiliaire qui travaille sur la partie de la liste comprise entre les indices deb et fin (inclus)'''
        if (fin>deb):
            pivot = lst[deb]
            frontiere = deb
            for k in range(deb+1, fin+1):
                if lst[k]<=pivot:
                    lst[k],lst[frontiere+1] = lst[frontiere+1],lst[k]
                    frontiere += 1
            lst[deb], lst[frontiere] = lst[frontiere],lst[deb]
            aux(deb, frontiere-1)
            aux(frontiere+1, fin)
    aux(0,len(lst)-1)
    


test = [randint(1,100) for _ in range(20)]
qsort(test)
print(test)