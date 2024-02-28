def solve(n):
    nums = [int(c) for c in input().split()]
    if len(set(nums)) == 1:
        ret = 0
        return ret
    l, r = 0, n -1
    while nums[l+1] == nums[l]:
        l += 1
    while nums[r-1] == nums[r]:
        r -= 1
    left = l + 1
    right = n - r 
    if nums[0] == nums[-1]:
        ret = n - left - right
    else:
        ret = n - max(left, right)
    return ret

T = int(input())
while T:
    n = int(input())
    ret = solve(n)
    print(ret)
    T -= 1

