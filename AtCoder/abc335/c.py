from collections import deque
def solve():
    n, q = [int(c) for c in input().split()]
    sz = n + q + 10
    xs = [0]*sz
    ys = [0]*sz
    begin_idx = q
    for i in range(n):
        xs[begin_idx + i] = i + 1
    for _ in range(q):
        l, r = input().split()
        if l == "2":
            r = int(r)
            idx = begin_idx + r - 1
            print(xs[idx], ys[idx])
        else:
            y = ys[begin_idx]
            x = xs[begin_idx]
            if r == "U":
                dy, dx = (1, 0)
            elif r == "D":
                dy, dx = (-1, 0)
            elif r == "L":
                dy, dx = (0, -1)
            else:
                dy, dx = (0, 1)
            new_y, new_x = y + dy, x + dx
            begin_idx -= 1
            xs[begin_idx] = new_x
            ys[begin_idx] = new_y
            
solve()
