def solve():
    n = int(input())
    H = n // 2
    ret = [[0]*n for _ in range(n)]
    visited = [[False]*n for _ in range(n)]
    visited[H][H] = True
    ret[H][H] = "T"
    idx = 1
    i, j = 0, 0
    directions = [(0, 1),(1, 0),(0, -1),(-1, 0)]
    d = 0
    ret[0][0] = 1
    visited[0][0]  = True
    while True:
        di, dj = directions[d%4]
        i += di
        j += dj
        if i < 0  or i >= n or j < 0 or j >=n or visited[i][j]:
            i -= di
            j -= dj
            d += 1
        else:
            idx += 1
            ret[i][j] = idx
            visited[i][j] = True
            if idx == n*n - 1:
                break
    for row in ret:
        print(" ".join(str(ele) for ele in row))

solve()




