def solve():
    nums = [int(c) for c in input().split()]
    ret = 0
    for num in nums:
        ret ^= num
    print(ret)
T = int(input())
for i in range(T):
    solve()
