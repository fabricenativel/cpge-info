N = 1000

def syracuse(n):
    if n%2 == 0:
        return n//2
    else:
        return 3*n+1

def check_collatz(n):
    top_value = n
    while n!=1:
        n = syracuse(n)
        if n>top_value:
            top_value = n
    return top_value

max_value = 0
for n in range(1,N+1):
    current =  check_collatz(n)
    if current>max_value:
        max_value = current
    print(f"Vérifié pour {n} - Max atteint : {max_value}")

