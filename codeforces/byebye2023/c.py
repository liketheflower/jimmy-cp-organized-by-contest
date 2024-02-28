def helper(even, odd, k):
    if k == 1:
        return 0
    if odd == 0:
        return 0
    """
    odd + odd = even
    A: odd + odd 
    B: odd + even: use one odd if it has a paired even
    A: odd + odd
    """
    ret = odd % 3 == 1
    return ret + (odd // 3)

def solve():
    n = int(input())
    nums = [int(c) for c in input().split()]
    cusum = [0]*(n+1)
    for i in range(n):
        cusum[i+1] = cusum[i] + nums[i]
    even, odd = 0, 0
    ret = [0]*n
    for i in range(n):
        if nums[i] & 1:
            odd += 1
        else:
            even += 1
        delta = helper(even, odd, i + 1)
        this_ret = cusum[i+1] - delta
        ret[i] = this_ret
    print(" ".join(str(r) for r in ret))
T = int(input())
for i in range(T):
    solve()
