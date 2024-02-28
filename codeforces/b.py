import collections
def solve():
    n = input()
    a, b = input(), input()
    cnt = collections.Counter()
    for c, d in zip(a, b):
       if  c != d:
           cnt[c] += 1
    #print(cnt)
    vals = list(cnt.values())
    if len(vals)>1:
        ret = sum(vals) -min(vals)
    else:
        ret = sum(vals)
    print(ret)
T = int(input())                                                                        
for i in range(T):                                                                      
    solve()  
