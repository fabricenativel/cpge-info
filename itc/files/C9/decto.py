CHIFFRES = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def dec_to_base(n, base):
    if n == 0:
        return "0"
    s = ""
    while n > 0:
        s = CHIFFRES[n % base] + s
        n //= base
    return s


def base_to_dec(n, base):
    dec = 0
    pow = 1
    for i in range(len(n)-1, -1, -1):
        dec += CHIFFRES.index(n[i]) * pow
        pow *= base
    return dec