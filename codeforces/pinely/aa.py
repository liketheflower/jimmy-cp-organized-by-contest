dirs = [(0, 1),(0, -1),(1, 0),(-1, 0)]
def solve():
    n = int(input())
    coordinates = set()
    axis0 = set()
    axis1 = set()
    up, down, left, right= [False]*4
    x_axis , y_axis= False, False
    for _ in range(n):
        x, y = [int(c) for c in input().split()]
        if x == 0 and y == 0:
            continue
        if x!= 0 and y > 0:

    return True




T = int(input())
for i in range(T):
    ret = solve()
    print("YES" if ret else "NO")
