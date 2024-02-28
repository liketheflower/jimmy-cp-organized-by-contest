import collections
def solve(C, R):
    nums = []
    for i in range(R):
        nums.append([int(c) for c in input().split()])
    if R == 1:
        return True
    def check(i1, i2):
        row1, row2 = nums[i1], nums[i2]
        firsttwo = [row1[0], row2[0]]
        f1, f2 = firsttwo
        a = [x for x in row1 if x not in firsttwo]
        j = 0
        for x in row2:
            if x in firsttwo:
                continue
            else:
                if x != a[j]:
                    return False
                j += 1
        return True
    for i in range(1, R):
        if not check(i-1, i):
            return False
    return True


    




T = int(input())
while T:
    C, R = [int(c) for c in input().split()]
    ret = solve(C, R)
    print("YES" if ret else "NO")
    T -= 1

