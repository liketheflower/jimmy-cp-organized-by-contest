def solve():
    n, f, a, b = [int(c) for c in input().split()]
    nums = [int(c) for c in input().split()]
    ret = 0
    begin_t = 0
    prev = 0
    ret = True
    #print(f)
    for i, num in enumerate(nums):
        min_consumption = min((num - prev)*a, b)
        #print("min_consumption", min_consumption)
        if min_consumption >= f:
            ret = False
            break
        else:
            f -= min_consumption
            prev = num
        #print(f)
    if ret:
        print("YES")
    else:
        print("NO")

T = int(input())                                                                        
for i in range(T):                                                                      
    solve()  
