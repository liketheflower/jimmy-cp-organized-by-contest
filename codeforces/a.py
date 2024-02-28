def solve():
    n = 4
    xys = [[int(ele) for ele in input().split()] for _ in range(n)]
    # sort by x and y
    xs = [x for x, y in xys]
    ys = [y for x, y in xys]
    ret = (max(xs)-min(xs))*(max(ys)-min(ys))
    print(ret)

T = int(input())
for i in range(T):
    solve()
