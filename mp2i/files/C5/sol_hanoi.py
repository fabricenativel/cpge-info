import hanoi

def resoud(n,depart,arrivee,intermediaire):
    if n==1:
        hanoi.deplace_disque(depart,arrivee)
    else:
        resoud(n-1,depart,intermediaire,arrivee)
        hanoi.deplace_disque(depart,arrivee)
        resoud(n-1,intermediaire,arrivee,depart)



hanoi.dessine_depart(5)
resoud(5,1,3,2)
hanoi.fin()