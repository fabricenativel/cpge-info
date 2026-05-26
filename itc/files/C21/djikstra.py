'''Plus court chemin dans un tableau nxn'''

import heapq
from functools import lru_cache
from time import perf_counter
from random import randint 

size = 200
carte = [[randint(1,9) for _1 in range(size)] for _2 in range(size)]


def in_grid(l,c):
    return (0<=l<size and 0<=c<size)


def djkistra(sl,sc,al,ac):
    todo = []
    seen =set()
    heapq.heappush(todo,(0,sl,sc))
    seen.add((sl,sc))
    end = False
    while not end:
        d,l,c = heapq.heappop(todo)
        if (l,c)==(al,ac):
            end = True
        for dl,dc in [(1,0),(0,1)]:
            if in_grid(l+dl,c+dc) and (l+dl,c+dc) not in seen:
                seen.add((l+dl,c+dc))
                heapq.heappush(todo,(d+carte[l+dl][c+dc],l+dl,c+dc))
    return d

@lru_cache
def progdyn(sl,sc,al,ac):
    if (sl,sc)==(al,ac):
        return 0
    else:
        if sc+1>=size:
            return carte[sl+1][sc]+progdyn(sl+1,sc,al,ac)
        if sl+1>=size:
            return carte[sl][sc+1]+progdyn(sl,sc+1,al,ac)
        if sl+1<size and sc+1<size:
            return min(carte[sl+1][sc]+progdyn(sl+1,sc,al,ac),carte[sl][sc+1]+progdyn(sl,sc+1,al,ac))

@lru_cache
def progdyn_desc(sl,sc,al,ac):
    if (sl,sc)==(al,ac):
        return 0
    else:
        if ac==0:
            return carte[al-1][0]+progdyn_desc(sl,sc,al-1,ac)
        if al==0:
            return carte[0][ac-1]+progdyn_desc(sl,sc,al,ac-1)
        if sl+1<size and sc+1<size:
            return min(carte[al-1][ac]+progdyn_desc(sl,sc,al-1,ac),carte[al][ac-1]+progdyn_desc(sl,sc,al,ac-1))

start = perf_counter()
print(djkistra(0,0,size-1,size-1))
end = perf_counter()
print(f"Djikstra : {end-start} s ")
start = perf_counter()
print(progdyn(0,0,size-1,size-1))
end = perf_counter()
print(f"Progdyn(Memoïsation) asc: {end-start} s ")
start = perf_counter()
print(progdyn_desc(0,0,size-1,size-1))
end = perf_counter()
print(f"Progdyn(Memoïsation) dsc: {end-start} s ")
