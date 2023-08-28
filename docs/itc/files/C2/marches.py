from functools import lru_cache
from random import shuffle,randint
@lru_cache
def marches(n):
    if n<2:
        return n
    return marches(n-1)+marches(n-2)

@lru_cache
def possibilites(n):
    if n==0: return []
    if n==1: return [[1]]
    return [p+[1] for p in possibilites(n-1)] + [p+[2] for p in possibilites(n-2)]


def write(n):
    to_write = possibilites(n)
    shuffle(to_write)
    to_write.pop(randint(0,len(to_write)))
    writer = open("montees.txt","w")
    for p in to_write:
        writer.write("".join([str(m) for m in p]))
        writer.write("\n")
    writer.close()

write(12)

