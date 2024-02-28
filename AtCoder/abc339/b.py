R, C, N = [int(c) for c in input().split()]
ret = [[False]*C for _ in range(R)]

UP = 0
DOWN = 1
LEFT = 2
RIGHT = 3

delta = {UP:(-1, 0), DOWN: (1, 0), LEFT:(0, -1), RIGHT:(0, 1)}

clock_wise = {UP: RIGHT, DOWN:LEFT, LEFT:UP, RIGHT: DOWN}
anti_clock_wise = {UP: LEFT, DOWN:RIGHT, LEFT:DOWN, RIGHT: UP}

direction = UP
i, j = 0, 0
for _ in range(N):
    if not ret[i][j]:# balck
        ret[i][j] = True
        direction = clock_wise[direction]
    else:
        ret[i][j] = False
        direction = anti_clock_wise[direction]
    di, dj = delta[direction]
    i += di
    j += dj
    i %= R
    j %= C

for row in ret:
    print("".join("#" if c else "." for c in row))
        

