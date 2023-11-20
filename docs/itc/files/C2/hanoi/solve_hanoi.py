import hanoi

def solve_hanoi(nb, dep, arr, inter):
    if nb==1:
        hanoi.deplace_disque(dep,arr)
    else:
        solve_hanoi(nb-1,dep,inter,arr)
        hanoi.deplace_disque(dep,arr)
        solve_hanoi(nb-1,inter,arr,dep)


def shanoi(nb):
    hanoi.dessine_depart(nb)
    solve_hanoi(nb,1,3,2)

shanoi(7)
hanoi.fin()