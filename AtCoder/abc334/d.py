import bisect
n, k = [int(c) for c in input().split()]
vals = [int(c) for c in input().split()]
vals.sort()
cusums = [0]*(n+1)
for i in range(1, n+1):
    cusums[i] = cusums[i-1] + vals[i-1]
for i in range(k):
    q = int(input())
    i = bisect.bisect_right(cusums, q)
    print(i-1)





