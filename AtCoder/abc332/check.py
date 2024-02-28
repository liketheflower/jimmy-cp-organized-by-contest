import itertools
a = []
n = int(input())
for i in range(n):
    x = input()
    a.append(x)
cols = ["".join(col) for col in zip(*a)]
#print(cols)
def find(idx, ii):
    ret = 0
    row = cols[idx]
    for i , j in itertools.combinations(range(n), 2):
        if row[i] == 'o' and row[j] == 'o':
            if ii in [i, j]:
                ret += 1
    return ret
cnts = [c.count('o') for c in cols]
tot_ret = 0
for row_i, row in enumerate(a):
    this_ret = 0
    for i , j in itertools.combinations(range(n), 2):
        if row[i] == 'o' and row[j] == 'o':
            #ret1 = find(i,row_i )
            #ret2 = find(j, row_i)
            ret1, ret2 = cnts[i] - 1, cnts[j]-1
            #print("i, j, ret1, ret2, thisret",i, j , ret1, ret2, this_ret)
            #print("alternative", cnts[i] - 1, cnts[j]-1)
            this_ret += ret1 + ret2
    #print("row this ret", row, this_ret)
    tot_ret += this_ret
print(tot_ret)


