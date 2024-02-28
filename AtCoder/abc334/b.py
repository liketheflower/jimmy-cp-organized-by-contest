a, k, l, r = [int(c) for c in input().split()]
ret = 0
"""
a + km = l
a + km = r
"""
small = (l - a) // k
large = (r - a) // k
ret = large - small + 1
if (l - a) % k != 0:
    ret -= 1
print(ret)
