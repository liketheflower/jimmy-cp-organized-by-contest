from functools import lru_cache
n = int(input())
edges = [[int(c) for c in input().split()] for _ in range(n-1)]

graph = [[] for _ in range(n+1)]
@lru_cache(None)
def dfs(i, p):
    ret = i - 1
    for j in graph[i]:
        if j == p:
            continue
        ret += dfs(j, i)
    return ret


ret = [dfs(i, -1) for i in range(1, n+1)]
print(" ".join(str(r) for r in ret))
    
