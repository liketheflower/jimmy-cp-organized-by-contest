import itertools
ALICE = 0
BOB = 1
def solve():
    n= int(input())
    a = [int(c) for c in input().split()]
    b = [int(c) for c in input().split()]
    A = sum(a)
    B = sum(b)
    ab = [(a_, b_, i) for i, (a_, b_) in enumerate(zip(a, b))]
    AA = sorted(ab, key=lambda x:x[0] - 1 - x[1], reverse=True)
    BB = sorted(ab, key=lambda x:x[1] - 1 - x[0], reverse=True)
    valid = [True]*n
    for i in range(n):
        if a[i] == 0 and b[i] == 0:
            valid[i] = False
    i, j = 0, 0
    cnt = 0
    while True:
        if cnt %2 == 0:
            while i < n and not valid[AA[i][2]]:
                i += 1
            if i >= n:
                break
            idx = AA[i][2]
            a[idx] -= 1
            b[idx] = 0
            i += 1
            valid[idx] = False
            if i >= n:
                break
        else:
            while j < n and not valid[BB[j][2]]:
                j += 1
            if j >= n:
                break
            idx = BB[j][2]
            a[idx] = 0
            b[idx] -= 1
            j += 1
            valid[idx] = False
            if j >= n:
                break
        cnt += 1
    print(sum(a) - sum(b))

        

T = int(input())                                                                        
for i in range(T):                                                                      
    solve()  
