
def solve1(k):                                                                     
    if k == 2: return 3
    delta =  k - 1
    for i in range(1, 1000000):
        sum_ = i*(i+1)//2
        if sum_ == delta:
            return 2*(i+1)
        elif sum_ > delta:
           return 2*i

for n in range(1000000000, 1000000000+10):
    print(n, solve1(n))

