n, m, k = [int(c) for c in input().split()]
def gcd(a,b): 
    if a == 0: 
        return b 
    return gcd(b % a, a) 
  
# Function to return LCM of two numbers 
def lcm(a,b): 
    return (a // gcd(a,b))* b 


lcm_ = lcm(n, m)
lo = 1
hi = k*(n + m + 10**4)
def get_num(mid):
    nn = mid // n
    mm = mid // m
    overlap = mid // lcm_
    return nn + mm - 2*overlap
while lo < hi:
    mid = (lo + hi) // 2
    num = get_num(mid)
    #print(mid, num)
    if num > k:
        hi = mid - 1
    elif num == k:
        if mid % n == 0 and mid % m == 0:
            hi = mid - min(n, m)
        elif mid % n != 0 and mid % m != 0:
            hi  = mid - min(mid % n, mid % m)
        else:
            lo = mid
            break
    else:
        lo = mid + 1
print(lo)
