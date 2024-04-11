from math import sqrt
from colorama import Fore, Style
from dataclasses import dataclass
from collections import deque
import graphviz

GAME_SIZE = 20
VALID = Style.BRIGHT + Fore.GREEN
NOT_VALID = Style.DIM + Fore.LIGHTRED_EX
NORMAL = Style.NORMAL + Fore.WHITE
REMOVED = Style.DIM + Fore.LIGHTWHITE_EX

@dataclass(frozen=True,eq=True)
class Game_state:
    game_size : int
    remaining : frozenset
    previous_move : int

    
    def start_position(game_size):
        return Game_state(game_size,frozenset({i for i in range(1,game_size+1)}),None)
    
    
    def get_possible_moves(self):
        if self.previous_move is None:
            return {2*i for i in range(1,self.game_size//2+1)}
        else:
            return self.remaining & possible_moves(self.game_size)[self.previous_move]

    def __str__(self):
        to_print = ""
        for n in range(1,self.game_size+1):
            if n not in self.remaining:
                to_print += f"{REMOVED} {n} "
            elif n in self.get_possible_moves():
                to_print += f"{VALID} {n} "
            else:
                to_print += f"{NOT_VALID} {n} "
        return to_print+NORMAL
    
    def play(self,move):
        possible_moves = self.get_possible_moves()
        if move not in possible_moves:
            return self
        new_remaining = set(self.remaining)
        new_remaining.remove(move)
        new_remaining = frozenset(new_remaining)
        new_state = Game_state(self.game_size,new_remaining,move)
        return new_state



def get_divisors(n):
    divisors = {i:{1,i} for i in range(1,n+1)}
    for div in range(2,int(sqrt(n))+1):
        m = 1
        while m*div<=n:
            divisors[m*div].add(div)
            divisors[m*div].add(m)
            m += 1
    return divisors
        
def get_multiples(n):
    multiples = {i:{i*k for k in range(1,n//i+1)}  for i in range(1,n+1)}
    return multiples

def possible_moves(n):
    m,d =  get_multiples(n) , get_divisors(n)
    return {i : m[i]|d[i] for i in range(1,n+1)}

def make_graph(n):
    start = Game_state.start_position(n)
    queue = deque()
    queue.appendleft(start)
    juniper_graph = {}
    while len(queue)!=0:
        current = queue.pop()
        if current not in juniper_graph:
            moves = current.get_possible_moves()
            next_states = []
            for m in moves:
                ngs = current.play(m)
                queue.append(ngs)
                next_states.append(ngs)
            juniper_graph[current] = next_states
    return juniper_graph

def frozen_to_str(fset):
    if len(fset)==0: 
        return "{}"
    else:
        return str(set(fset))

juniper = make_graph(5)
print(len(juniper))
juniper_graph = graphviz.Digraph()
for s in juniper:
    if len(s.get_possible_moves())==0:
        fcolor="black"
    else:
        fcolor="black"
    if len(s.remaining)%2==1:
        juniper_graph.node(name=str(hash(s)),label=frozen_to_str(s.remaining),shape="oval",fillcolor="salmon",style="filled",fontcolor=fcolor)
    else:
        juniper_graph.node(name=str(hash(s)),label=frozen_to_str(s.remaining),shape="box",fillcolor="lightblue",style="filled",fontcolor=fcolor)
for s in juniper:
    for e in juniper[s]:
        juniper_graph.edge(str(hash(s)),str(hash(e)),label=str(e.previous_move))
juniper_graph.view()
    
