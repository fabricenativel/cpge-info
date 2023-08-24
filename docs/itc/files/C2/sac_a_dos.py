OBJETS = [
    (90,0.2),
    (1100,2.4),
    (140,0.3),
    (380,0.8),
    (485,1.1),
    (620,1.4),
    (1320,2.8),
    (440,1)
]
PMAX = 4

def solve(objets,pmax):
    if pmax<min(objets,key=lambda x:x[1])[1]: return 