"""
b*k1 = x
a*k2 = x
"""


import math
def solve():
    a, b = [int(c) for c in input().split()]
    lcm_ = math.lcm(a, b)
    ret = lcm_
    if ret == b:
        ret*= math.gcd(a, b)
    print(ret)

T = int(input())
for i in range(T):
    solve()
