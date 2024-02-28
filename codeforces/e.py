import itertools
ALICE = 0
BOB = 1
def solve():
    n= int(input())
    a = [int(c) for c in input().split()]
    b = [int(c) for c in input().split()]
    valid = [True]*n
    for i in range(n):
        if a[i] == 0 and b[i] == 0:
            valid[i] = False
    def backtrack(turn, a, b, valid):
        if sum(valid) == 0:
            return sum(a) - sum(b)
        if turn == ALICE:
            possibles = []
            for i, ok in enumerate(valid):
                if ok:
                    new_a = a[:]
                    new_b = b[:]
                    new_a[i] -= 1
                    new_b[i] = 0
                    valid_new = valid[:]
                    valid_new[i] = False
                    this_ret = backtrack(1-turn, new_a,new_b, valid_new)
                    possibles.append((this_ret, i))
            ret, i = max(possibles, key=lambda x:x[0])
            return ret
        else:
            possibles = []
            for i, ok in enumerate(valid):
                if ok:
                    new_a = a[:]
                    new_b = b[:]
                    new_a[i] = 0
                    new_b[i] -= 1
                    valid_new = valid[:]
                    valid_new[i] = False
                    this_ret = backtrack(1-turn, new_a,new_b, valid_new)
                    possibles.append((this_ret, i))
            ret, i = min(possibles, key=lambda x:x[0])
            return ret
    ret = backtrack(ALICE, a, b, valid)
    print(ret)

T = int(input())                                                                        
for i in range(T):                                                                      
    solve()  
