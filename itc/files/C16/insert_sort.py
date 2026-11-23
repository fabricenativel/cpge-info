from random import randint

def insert_elt(elt,sorted_list):
    current_index = 0
    while current_index<len(sorted_list) and elt>sorted_list[current_index]:
        current_index = current_index + 1
    sorted_list.insert(elt,current_index)

def insert_sort(l):
    sl = []
    for elt in l:
        insert_elt(elt,sl)
    return sl

print(insert_sort([randint(1,100) for _ in range(50)]))