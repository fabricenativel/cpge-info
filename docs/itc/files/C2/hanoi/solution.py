import hanoi

def solve_hanoi(nb,dep,arr,int):
    if nb==1:
        hanoi.deplace_disque(dep,arr)
    else:
        solve_hanoi(nb-1,dep,int,arr)
        hanoi.deplace_disque(dep,arr)
        solve_hanoi(nb-1,int,arr,dep)


def shanoi(n):
    hanoi.dessine_depart(n)
    solve_hanoi(n,1,3,2)
    hanoi.fin()


shanoi(6)