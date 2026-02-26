import hanoi

def resoud(nb,dep,arr,int):
    if nb==1:
        hanoi.deplace_disque(dep,arr)
    else:
        resoud(nb-1,dep,int,arr)
        hanoi.deplace_disque(dep,arr)
        resoud(nb-1,int,arr,dep)

hanoi.dessine_depart(8)
resoud(8,1,3,2)
hanoi.fin()

