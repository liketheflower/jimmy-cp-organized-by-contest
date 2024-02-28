def solve():
    n, k = [int(c) for c in input().split()]
    b = [int(c) for c in input().split()]
    prod = 1
    for ele in b:
        prod *= ele
    if 2023 % prod != 0:
        print("NO")
        return
    print("YES")
    ret = [2023 //prod ] + [1]*(k - 1)
    print(" ".join(str(r) for r in ret))

T = int(input())
for i in range(T):
    solve()
