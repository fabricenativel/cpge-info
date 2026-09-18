def bin_to_dec(ecbin):
    dec = 0
    pow = 1
    for i in range(len(ecbin)-1, -1, -1):
        if ecbin[i]=='1':
            dec += pow
        pow *= 2
    return dec