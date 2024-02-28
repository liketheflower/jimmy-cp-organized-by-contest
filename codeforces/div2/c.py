import collections
def solve():
    n, k, m = [int(c) for c in input().split()]
    s = input()
    candidates = "".join([chr(ord("a") + i) for i in range(k)])
    cnt = collections.Counter(s)
    for c in candidates:
        if cnt[c] < n:
            print("NO")
            print(c*n)
            return
    inorder = candidates
    def helper(inorder):
        i = 0
        for c in s:
            if c == inorder[i]:
                i += 1
                if i >= k:
                    break
        else:
            print("NO")
            print(inorder)
            return False
        return True
    if helper(inorder):
        if helper(candidates[::-1]):
            print("YES")
            return


T = int(input())
for i in range(T):
    solve()
