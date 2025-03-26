from random import randint

def echange(lst, i, j):
    assert 0<= i < len(lst) and 0<=j < len(lst)
    lst[i], lst[j] = lst[j], lst[i]

def melange_iteratif(lst):
    for i in range(len(lst)-1, 0, -1):
        j = randint(0, i)
        echange(lst, i, j)

def melange_recursif(lst, i):
    if i> 0:
        j = randint(0, i)
        echange(lst, i, j)
        melange_recursif(lst, i-1)

