def solve(n):
    candidates = []
    for i in range(1, 27):
        for j in range(1, 27):
            for k in range(1, 27):
                if i + j + k == n:
                    candidates.append(chr(ord('a') + i - 1) + chr(ord("a") + j -1) + chr(ord("a") + k -1))
    print(min(candidates))
T = int(input())
while T:
    n = int(input())
    solve(n)
    T -= 1

