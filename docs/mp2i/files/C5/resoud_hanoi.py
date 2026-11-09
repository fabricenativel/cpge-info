import hanoi

def resoud(nb_disque, depart, pivot, arrivee):
    # Cas de base
    if nb_disque==1:
        hanoi.deplace_disque(depart, arrivee)
    # Appels récursifs
    else:
        resoud(nb_disque-1, depart, arrivee, pivot)
        hanoi.deplace_disque(depart, arrivee)
        resoud(nb_disque-1, pivot, depart, arrivee)

hanoi.dessine_depart(8)
resoud(8, 1, 2, 3)
hanoi.fin()
