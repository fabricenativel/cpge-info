def visualise(polynome):
    for  i in range(len(polynome)):
        if polynome[i]!=0:
            if polynome[i]>0 and i!=0:
                sgn = "+"
            else:
                sgn = ""
            if i==0:
                print(sgn+str(polynome[i]),end='')
            elif i==1:
                print(f"{sgn}{polynome[i]}x",end='')
            else:
                print (f"{sgn}{polynome[i]}x^{i}",end='')
    print()

def evalue(polynome, x):
    p = 1
    v = 0
    for k in polynome:
        v += k*p
        p = p *x
    return v

def dichotomie(polynome, a, b):
    if evalue(polynome,a)*evalue(polynome,b) > 0:
        return None
    while b!=a:
        mid = (a+b)/2
        if evalue(polynome,a)*evalue(polynome,mid)<0:
            b = mid
        else:
            a = mid
    return a

a = dichotomie([1, -3, 3, 1],-5,5)
print(evalue([1,-3,3,1],a))