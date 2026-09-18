def mystere(a: int, b: int) -> int:
    assert (a >= 0 and b > 0)
    q = 0
    while (a-b >= 0):
        a = a - b
        q = q + 1
    return q
