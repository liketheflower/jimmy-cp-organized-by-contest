T = int(input())
for _ in range(T):
    n = input()
    s = input()
    neg = s.count("-")
    pos = s.count("+")
    ret = abs(neg - pos)
    print(ret)
