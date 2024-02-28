N, D = [int(c) for c in input().split()]
nums = [int(c) for c in input().split()]
INF = 1e9
diff = ""
for i in range(1, N):
    good = abs(nums[i] - nums[i-1]) <= D
    if good:
        diff += "P"
    else:
        diff += "F"
s = diff.split("F")
ret = 0
if s:
    ret = max(len(c) for c in s) + 1
print(ret)
