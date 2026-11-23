def butin(maisons, memo, k):
    if k in memo:
        return memo[k]
    n = len(maisons)
    if k>n-1:
        memo[k] = 0
        return 0
    if k==n-1:
        memo[k] = maisons[n-1]
        return memo[k]
    avec_k = maisons[k] + butin(maisons, memo, k+2)
    sans_k = butin(maisons, memo, k+1)
    memo[k] = max(avec_k, sans_k)
    return max(avec_k, sans_k)

def solution(maisons, memo):
    solutions = []
    n = len(maisons)
    k= 0
    while k<n-1:
        if maisons[k] + memo[k+2] > memo[k+1]:
            solutions.append(k)
            k = k + 2
        else:
            k=k+1
    return solutions

test = [12, 20, 31, 18, 29, 17]
mem = {}
print(butin(test, mem,0))
print(solution(test,mem))

