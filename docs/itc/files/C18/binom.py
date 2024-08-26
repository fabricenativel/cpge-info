def binom(n,p):
    if p==0 or n==p:
        return 1
    return binom(n-1,p-1)+binom(n-1,p)

print(binom(28,12))