

def u(n,alpha,tau):
    return alpha**n+tau

def v(n,alpha,tau):
    return u(n,alpha,tau)/u(n+1,alpha,tau)

alpha = float(input("alpha = "))
beta = float(input("beta = "))
tau = float(input("tau = "))
a = (alpha+beta)
b = -alpha*beta
c = tau*(1-a-b)
lamda = float(input("lambda = "))
u0 = lamda + tau
u1 = lamda*alpha + tau

print(f"a = {a}")
print(f"b = {b}")
print(f"c = {c}")
print(f"u0 = {u0}")
print(f"u1 = {u1}")
print(f"u(n+2) = {a} u(n+1) + {b} u(n) + {c}")
print(f"v1 = {u1}/{u0} = {u1/u0}")
print(f"v1 = {u(2,alpha,tau)}/{u1} = {u(2,alpha,tau)/u1}")
print(f"v(n+2)= {a+1} + {b-a}/v(n+1) - {b}/(v(n)v(n+1))")