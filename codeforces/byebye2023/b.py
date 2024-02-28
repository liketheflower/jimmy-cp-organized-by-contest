import collections

def prime_factors__(n):
    spf = [0 for i in range(n+1)]
    spf[1] = 1
    for i in range(2, n+1):
        spf[i] = i
    for i in range(4, n+1, 2):
        spf[i] = 2
  
    for i in range(3, int(n**0.5)+1):
        if spf[i] == i:
            for j in range(i*i, n+1, i):
                if spf[j] == j:
                    spf[j] = i
                      
    ret = []
    while n != 1:
        ret.append(spf[n])
        n = n // spf[n]
    return ret


def prime_factors(n):
    ret = [] 
    # Print the number of two's that divide n
    while n % 2 == 0:
        ret.append(2)
        n = n // 2
         
    # n must be odd at this point
    # so a skip of 2 ( i = i + 2) can be used
    for i in range(3,int(math.sqrt(n))+1,2):
         
        # while i divides n , print i and divide n
        while n % i== 0:
            ret.append(i)
            n = n // i
             
    # Condition if n is a prime
    # number greater than 2
    if n > 2:
        ret.append(n)
    return ret

def prime_factorsi22(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

import math
def solve():
    a, b = [int(c) for c in input().split()]
    g = math.gcd(a, b)
    a = a // g
    b = b // g
    factors1 = prime_factors(a)
    factors2 = prime_factors(b)
    cnt1 = collections.Counter(factors1)
    cnt2 = collections.Counter(factors2)
    needed = []
    for k, v in cnt1.items():
        if v > cnt2[k]:
            needed += [k]*(v - cnt2[k])

    ret = b*g
    for fact in needed:
        ret *= fact
    if ret == b*g:
        ret*= min(factors2 + factors1 + prime_factors(g))
    print(ret)

T = int(input())
for i in range(T):
    solve()
