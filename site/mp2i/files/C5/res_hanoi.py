import hanoi

def resoud_hanoi(nb, dep, arr, inter):
    if (nb == 1):
        hanoi.deplace_disque(dep, arr)
    else:
        resoud_hanoi(nb-1, dep, inter, arr)
        hanoi.deplace_disque(dep, arr)
        resoud_hanoi(nb-1, inter, arr, dep)

def solution(n):
    resoud_hanoi(n, 1, 3, 2)

n = 6
hanoi.dessine_depart(n)
solution(n)
hanoi.fin()