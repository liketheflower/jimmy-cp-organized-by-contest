N = int(input())
nums = [int(c) for c in input().split()]
INF = 1e9
min_v = INF
cusum = 0
for num in nums:
    cusum += num
    min_v = min(min_v, cusum)
if min_v >= 0:
    print(cusum)
else:
    print(cusum-min_v)
