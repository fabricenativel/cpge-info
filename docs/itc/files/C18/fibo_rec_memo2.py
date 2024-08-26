from functools import lru_cache

@lru_cache
def fibonacci(n):
    assert n>=0
    if n<2:
        return n
    return fibonacci(n-1)+fibonacci(n-2)