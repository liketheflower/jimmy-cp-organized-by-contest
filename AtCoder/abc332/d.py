import itertools
INF = 1 << 60
H, W = [int(ele) for ele in input().split()]
A = [[int(ele) for ele in input().split()] for _  in range(H)]
B = [[int(ele) for ele in input().split()] for _  in range(H)]


def ff(row, original):
    if len(original) <= 1:return 0
    idx = original.index(row[0])
    original = original[:idx] + original[idx + 1:]
    return idx + ff(row[1:], original)
def f(row, col):
    grid_a = [A[i][:] for i in row]
    cols_a = [list(c) for c in zip(*grid_a)]
    grid_aa = [cols_a[i] for i in col]
    grid_aaa = [list(c) for c in zip(*grid_aa)]
    if grid_aaa == B:
        return True, ff(list(row), [i for i in range(H)]) + ff(list(col), [j for j in range(W)])
    return False, INF

def solve():
    ret = INF
    for row in itertools.permutations(range(H)):
        for col in itertools.permutations(range(W)):
            ok, this_ret = f(row, col)
            if not ok:
                continue
            ret = min(this_ret, ret)
    ret = -1 if ret == INF else ret
    print(ret)

solve()
