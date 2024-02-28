n = int(input())
scores = [[int(c) for c in input().split()] for _ in range(n)]
X = sum(x for x,  y in scores)
Y = sum(y for x, y in scores)
if X > Y:
    print("Takahashi")
elif Y > X:
    print("Aoki")
else:
    print("Draw")

