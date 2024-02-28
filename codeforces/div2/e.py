def solve():
    n = int(input())
    nums = [int(c) for c in input().split()]
    seen = {0}
    odd, even = 0, 0
    ret = "NO"
    for i, num in enumerate(nums):
        if i & 1:
            odd += num
        else:
            even += num
        diff = odd - even
        if diff in seen:
            ret = "YES"
            break
        seen.add(diff)
    print(ret)
T = int(input())
for i in range(T):
    solve()
