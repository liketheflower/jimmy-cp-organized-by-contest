def solve(n):
    nums = [int(c) for c in input().split()]
    avg = sum(nums) // n
    remain = 0
    ok = True
    for num in nums:
        if num <  avg:
            if avg - num > remain:
                ok = False
                break
            else:
                remain -=  avg - num
        else:
            remain += num - avg
    if ok:
        print("YES")
    else:
        print("NO")


T = int(input())
while T:
    n = int(input())
    solve(n)
    T -= 1

