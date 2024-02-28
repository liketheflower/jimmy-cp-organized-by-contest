f, l, d = [int(c) for c in input().split()]
ret = list(range(f, l + d - 1, d))
if d == 1:
    if f == l:
        ret.append(f)
    else:
        ret.append(l)

print(" ".join([str(r) for r in ret]))
