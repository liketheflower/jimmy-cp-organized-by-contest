def solve():
    rows = [input() for _ in range(3)]
    for row in rows:
        if "?" in row:
            for c in "ABC":
                if c not in row:
                    print(c)
                    break
T = int(input())
for i in range(T):
    solve()
