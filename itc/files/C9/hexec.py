def valeur_chiffre(c):
    if c >= '0' and c <= '9':
        return int(c)
    else:
        return ord(c) - ord('A') + 10
    
def hex_to_dec(hex):
    dec = 0
    pow = 1
    for i in range(len(hex)-1, -1, -1):
        dec += valeur_chiffre(hex[i]) * pow
        pow *= 16
    return dec