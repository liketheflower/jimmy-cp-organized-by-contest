def solve():
    n = int(input())
    nums = [int(c) for c in input().split()]
    tot = sum(nums)
    width = int(tot**0.5)
    ret = width*width == tot
    print("YES" if ret else "NO")
T = int(input())
for i in range(T):
    solve()
