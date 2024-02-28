n= int(input())
Q, A, B = [[int(c) for c in input().split()] for _ in range(3)]
ret = 0
i = 0
while True:
    a = [i*a_ <= q for q,a_  in zip(Q,A)]
    if not all(a):
        break
    b = [(q-i*a_) // b_ for q,a_, b_  in zip(Q,A, B) if b_ != 0]
    min_b = min(b)
    this_ret = i + min_b
    ret = max(ret, this_ret)
    i += 1
print(ret)

