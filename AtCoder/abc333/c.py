#a = [1,11,111, 1111, 11111, 111111, 1111111, 11111111, 111111111]
a = [int("1"*c) for c in range(1, 15)]
candidates = []
def dfs(i, curr):
    if len(curr) == 3:
        candidates.append(sum(curr))
        return
    if i >= len(a):
        return
    # take
    if len(curr) < 3:
        dfs(i, curr + [a[i]])
    # not take
    dfs(i + 1, curr)

dfs(0 , [])
#candidates = [sum(c) for c in candidates ]
candidates.sort()
idx = int(input())
#for idx in range(1, 334):
print(candidates[idx - 1])

