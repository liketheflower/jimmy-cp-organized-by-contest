n = int(input())
ret = []
for i in range(n):
    type_, num = [int(c) for c in input().split()]
    if type_ == 1:
        ret.append(num)
    else:
        print(ret[-num])

