INF = 1e10
def solve():
    n = int(input())
    candidates = [[] for _ in range(n+1)]
    vals = []
    for i in range(n):
        a, b = [int(c) for c in input().split()]
        if a == 1:
            candidates[b].append(i)
        vals.append((i, a, b))
    need_pickup = [False for _ in range(n+1)]
    for i, a, b in vals[::-1]:
        if a == 2:
            while candidates[b] and candidates[b][-1] > i:
                candidates[b].pop()
            if not candidates[b]:
                print(-1)
                return
            need_idx = candidates[b].pop()
            need_pickup[need_idx] = True
    ret = -INF
    curr_sum = 0
    for i, a, b in vals:
        curr_sum += need_pickup[i]
        curr_sum -= a == 2
        ret = max(ret, curr_sum)
    print(ret)
    print(" ".join([str(int(u)) for u, v in zip(need_pickup, vals) if v[1] == 1]))
solve()  

