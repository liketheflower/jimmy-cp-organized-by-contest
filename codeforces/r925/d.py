import collections
def solve(n, x, y):
    cnt = collections.defaultdict(int)
    nums = [int(c) for c in input().split()]
    ret = 0
    #print(nums)
    for num in nums:
        mod1 = num % x
        mod2 = num % y
        key = (mod1, mod2)
        key2 = ((x  - mod1)%x, mod2)
        ret += cnt[key2]
        cnt[key] += 1
    return ret


T = int(input())
while T:
    n, x, y = [int(c) for c in input().split()]
    ret = solve(n, x, y)
    print(ret)
    T -= 1

