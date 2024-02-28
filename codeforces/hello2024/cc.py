def lengthOfLIS(nums):
    nums = [-num for num in nums]
    n = len(nums)
    ans = []
    ans.append(0)
    for i in range(1, n):
      if nums[i] >= nums[ans[-1]]:
       ans.append(i)
      else:
       low = 0
       high = len(ans) - 1
       while low < high:
        mid = low + (high - low) // 2
        if nums[ans[mid]] < nums[i]:
         low = mid + 1
        else:
         high = mid
       ans[low] = i
    return ans






T = int(input())
for _ in range(T):
    n = int(input())
    s = [int(c) for c in input().split()]
    candidates = []
    for i in range(n-1):
        if s[i+1] > s[i]:
            candidates.append(s[i+1])
    if not candidates:
        print("0")
    else:
        m = len(candidates)
        if m == 1:
            print(m - 1)
        else:
            min_sofa = candidates[-1]
            for i in range(m -1, -1, -1):
                if candidates[i] > min_sofa:
                    print(m - 2)
                    break
                else:
                    min_sofa = candidates[i]
            else:
                print(m-1)
