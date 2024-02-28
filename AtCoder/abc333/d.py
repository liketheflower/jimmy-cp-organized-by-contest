import collections
def solve():
    n = int(input())
    graph = collections.defaultdict(list)
    for i in range(n-1):
        u, v = [int(c) for c in input().split()]
        graph[u].append(v)
        graph[v].append(u)
    if len(graph[1]) == 0:
        return 0
    if len(graph[1]) == 1:
        return 1
    def cnt_nei(i, curr=1):
        seen = [False]*(n+1)
        seen[curr] = True
        seen[i] = True
        cnt = 1
        stack = [i]
        while stack:
            node = stack.pop()
            seen[node] = True
            for j in graph[node]:
                if not seen[j]:
                    seen[j] = True
                    cnt += 1
                    stack.append(j)
        return cnt
    neighbors = [cnt_nei(v) for v in graph[1]]
    #print(neighbors)
    #print(graph[1])
    return sum(neighbors) - max(neighbors) + 1

print(solve())

