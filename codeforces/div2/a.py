import collections
def solve():
    n, k = [int(c) for c in input().split()]
    if k == 1:
        print("a"*n)
        return
    ss = [chr(ord("a") + i) for i in range(k)] 
    cnt = collections.defaultdict(int)
    ret = ""
    update = True
    count = 0
    s = ss
    while update:
        update = False
        for c in s:
            if cnt[c] == n:
                continue
            else:
                update = True
                ret += c
                cnt[c] += 1
        if count % 2 ==0:
            s = ss[::-1]
        else:
            s = ss
        count += 1
    print(ret)
T = int(input())
for i in range(T):
    solve()
