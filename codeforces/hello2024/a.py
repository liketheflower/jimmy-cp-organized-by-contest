T = int(input())
for _ in range(T):
    a, b = [int(c) for c in input().split()]
    if (a + b) % 2 == 0:
        print("Bob")
    else:
        print("Alice")
