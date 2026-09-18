from functools import cache

def matrix_chain_order(dims: list[int]) -> int:
    @cache
    def a(i, j):
        return min((a(i, k) + dims[i] * dims[k] * dims[j] + a(k, j) 
                   for k in range(i + 1, j)), default=0)

    return a(0, len(dims) - 1)

dims = [30, 35, 15, 5, 10, 20, 25, 30, 40, 50, 60]
print(matrix_chain_order(dims))