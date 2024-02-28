H, W, K = [int(c) for c in input().split()]
grids = [input() for _ in range(H)]
INF = 10000_00000
ret  = INF
def solve(row, K):
    if len(row) - row.count("x") < K:
        return INF
    curr = 0
    ret = INF
    this_ret = 0
    for i, c in enumerate(row):
        if c == "x":
            this_ret = 0
            curr = 0
        elif c == ".":
            this_ret += 1
            curr += 1
            if curr == K:
                ret = min(ret, this_ret)
            if curr > K:
                curr -= 1
                # 0, 1, 2, k = 2
                this_ret -= row[i-K] == '.'
                ret = min(ret, this_ret)

        else:
            curr += 1
            if curr == K:
                ret = min(ret, this_ret)
            if curr > K:
                curr -= 1
                # 0, 1, 2, k = 2
                this_ret -= row[i-K] == '.'
                ret = min(ret, this_ret)

    return ret
for i in range(H):
    ret = min(ret, solve(grids[i], K))
grids_col = ["".join(col) for col in zip(*grids)]
for j in range(W):
    ret = min(ret, solve(grids_col[j], K))
if ret == INF:
    print(-1)
else:
    print(ret)
