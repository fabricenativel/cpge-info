from math import perm, exp

def exacte(N,n):
    return perm(N,n)/N**n

def approx(N,n):
    return exp(-n*(n-1)/(2*N))
