import hanoi 

'''
Dans le module hanoi, on dispose des fonctions suivantes :
* dessine_depart(nb_disque) qui dessine la position de départ avec nb_disque < 9
* fin() qui attend un clic de souris puis ferme la fenêtre graphique
* deplace_disque(t1, t2) qui déplace un disque de la tour t1 vers la tour t2 si le mouvement est possible
'''

def solution(n, dep, arr, inter):
    if n==1:
        print(f"{dep} -> {arr}")
        #hanoi.deplace_disque(dep, arr)
    else:
        solution(n-1, dep, inter, arr)
        #hanoi.deplace_disque(dep, arr)
        print(f"{dep} -> {arr}")
        solution(n-1, inter, arr, dep)

nb_disque = 10
#hanoi.dessine_depart(nb_disque)
solution(nb_disque, 1, 3, 2)
