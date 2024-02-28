import itertools

N = int(input())
ret = [(a, b, c) for a, b, c in itertools.product(*[range(N+1)]*3) if a + b + c <= N]
ret.sort()
for row in ret:
    print(" ".join([str(r) for r in row]) )
