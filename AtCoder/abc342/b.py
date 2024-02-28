n = int(input())
nums = [int(c) for c in input().split()]
m = int(input())
num_idx = {num:i for i, num in enumerate(nums)}
for _ in range(m):
    a, b = [int(c) for c in input().split()]
    if num_idx[a] < num_idx[b]:
        print(a)
    else:
        print(b)

