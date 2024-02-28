from functools import lru_cache
N = int(input())
@lru_cache(None)
def f(n):
    if n <= 1:
        return 0
    half = n // 2
    return n + f(half) + f(half + (n&1))
print(f(N))
