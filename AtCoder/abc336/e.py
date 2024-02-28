INF = 1e10
MOD = 998244353
def solve():
    n = int(input())
    A = [int(c) for c in input().split()]
    cusum = [0]*(n+1)
    for i in range(n-1,-1, -1):
        if i == n - 1:
            cusum[i] = 1
            continue
        idx = A[i] + i
        cusum[i] = cusum[i+1] + 1
        if idx < n:
            cusum[i] += cusum[idx]
        if cusum[i] >= MOD:
            cusum[i] %= MOD
    def f(a):
        return a*(1+a)//2
    prefix_sum = [0]*(n+1)
    for i in range(n-1,-1, -1):
        prefix_sum[i] = prefix_sum[i+1] + cusum[i]
        if prefix_sum[i] >= MOD:
            prefix_sum[i] %= MOD
    ret = 1
    if A[0] + 1 < n:
        ret += f(prefix_sum[A[0]])
    if ret >= MOD:
        ret %= MOD
    print(A)
    print(cusum)
    print(prefix_sum)
    print(sum(cusum))
    print(sum(prefix_sum))
    print("ret", ret)

solve()  

