import bisect
def solve():
    print("^"*20)
    n = int(input())
    ab = [[int(c) for c in input().split()] for i in range(n)]
    bs = [b for a, b in ab]
    bs.sort()
    ret = 0
    for a, b in ab:
        # how many bs are in (a, b)
        print(bs, a, b)
        idx1 = bisect.bisect_right(bs, a)
        idx2 = bisect.bisect_left(bs, b)
        ret += idx2 - idx1
        print("idx 1 idx 2", idx1, idx2)
    print(ret)
T = int(input())
for i in range(T):
    solve()
