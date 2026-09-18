

def next(u, k):
    return k*u*(1-u)

un = 0.5
k = 3.42
seen = set()
cpt = 0
while un not in seen:
    seen.add(un)
    cpt += 1
    un = next(un,k)


for _ in range(100):
    print(f"u{cpt} = {un}")
    cpt += 1
    un = next(un,k)    