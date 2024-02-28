def solve():
    n = int(input())
    s = input()
    if not s:
        print(s)
        return
    ret = ""
    C, V = 0,  1
    prev = C
    def is_v(c):
        return c in "ae"
    def is_c(c):
        return not is_v(c)
    j = 0
    while j < n:
        # CVC pattern CVCC
        if j + 3 < n and is_c(s[j+3]):
            ret += s[j:j+3]
            j += 3
        elif j + 3 == n:
            ret += s[j:j+3]
            j += 3
        else:
            ret += s[j:j+2]
            j += 2
        ret += "."
    ret = ret[:-1]
    print(ret)
T = int(input())
for i in range(T):
    solve()
