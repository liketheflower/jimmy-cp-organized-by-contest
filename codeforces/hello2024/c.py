import bisect
def lengthOfLIS(nums):
    nums = [-num for num in nums]
    n = len(nums)
    p = [-1]*n
    list_end = 0
    L = []
    L_id = [0]*n
    lis_end = 0
    for i in range(n):
        pos = bisect.bisect_right(L, nums[i])
        L_id[pos] = i
        p[i] = L_id[pos-1] if pos > 0 else -1
        if pos == len(L):
            L.append(nums[i])
            lis_end = i
        L[pos] = nums[i]

    idxes = []
    i = lis_end
    while i != -1:
        idxes.append(i)
        i = p[i]
    #print(idxes)
    return idxes





T = int(input())
for _ in range(T):
    n = int(input())
    s = [int(c) for c in input().split()]
    ret = 0
    lis = lengthOfLIS(s)
    #print(lis)
    used = [False]*n
    for i in lis:
        used[i] = True
    b = [s[i] for i in range(len(s)) if not used[i]]
    if not b:
        print("0")
    else:
        # print("b", b)
        for i in range(len(b) - 1):
            ret += b[i+1] > b[i]
        print(ret)
