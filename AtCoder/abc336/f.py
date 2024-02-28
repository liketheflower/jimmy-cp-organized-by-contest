import numpy as np
R, C = [int(ele) for ele in input().split()]
a = [[int(ele) for ele in input().split()] for _ in range(R) ]
a = np.array(a, dtype=int)
def solve(R, C, a):
    Q = [(0, 0), (0, 1), (1, 0), (1, 1)]
    level = 1
    curr_level =[-1]
    while True:
        next_level = []
        for i in curr_level:
            for j in range(4):
                if j != i:
                    next_level.append(j)



solve(R, C, a)
