import itertools
def solve():
    n= int(input())
    a = [int(c) for c in input().split()]
    b = [int(c) for c in input().split()]
    d = [int(c) for c in input().split()]
    ret = 0
    ai = [(i, c) for i, c in enumerate(a)]
    bi = [(i, c) for i, c in enumerate(b)]
    di = [(i, c) for i, c in enumerate(d)]
    ai.sort(key =lambda x: x[1], reverse=True)
    bi.sort(key=lambda x: x[1], reverse=True)
    di.sort(key=lambda x: x[1], reverse=True)
    selected = set()
    for i, c in ai[:9] + bi[:9] + di[:9]:
        selected.add(i)
    abc = []
    for j in selected:
        abc.append((a[j], b[j], d[j]))
    n = len(abc)
    ret = 0
    #print(abc)
    #print("n", n) 
    for i, j, k in itertools.permutations(range(n), 3):
        #print(i, j, k)
        this_ret = abc[i][0] + abc[j][1] + abc[k][2]
        ret = max(ret, this_ret)
    print(ret)


T = int(input())                                                                        
for i in range(T):                                                                      
    solve()  
