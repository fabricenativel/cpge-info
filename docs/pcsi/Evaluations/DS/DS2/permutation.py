def insere(lst, elt):
    return [lst[:i] + [elt] + lst[i:] for i in range(len(lst)+1)]

def permutation(lst):
    if len(lst) == 0:
        return [[]]
    temp =  permutation(lst[1:])
    res = []
    for x in temp:
        res += insere(x, lst[0])
    return res