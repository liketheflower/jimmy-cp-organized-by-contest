n = int(input())
nums = [int(ele) for ele in input().split()]
def solve(n, nums):
    def good(mid):
        if mid == 1:
            return True
        curr = 1
        cnt = 0
        for i in range(len(nums)):
            if nums[i] >= curr:
                cnt += 1
                if cnt >= mid:
                    curr -= 1
                    if curr == 0:
                        return True
                else:
                    curr += 1
            else:
                curr = nums[i] + 1
                cnt =  nums[i]
        return False
    lo, hi = 1, 2+(len(nums) // 2)
    while lo < hi:
        mid = (lo + hi + 1) // 2
        ret = good(mid)
        #print(mid, ret)
        if ret:
            lo = mid
        else:
            hi = mid - 1
    print(lo)
solve(n, nums)
