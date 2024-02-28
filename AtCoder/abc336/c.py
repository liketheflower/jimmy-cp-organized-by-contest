a = int(input())
ret = 0
curr = 5
candidates = "02468"
candidates1 = "2468"
def solve(curr, a, first=False):
    # curr > a
    #print("curr", curr, a)
    if curr <= 5:
        return candidates[a-1]
    NUM = 4 if first else 5
    prev_curr = curr // NUM
    this_digit_i = int((a-1) / prev_curr)
    #print("curr", curr, "prev_curr", prev_curr, this_digit_i, a)
    if first:
        this_digit = candidates1[this_digit_i-1]
    else:
        this_digit = candidates[this_digit_i]
    #print("curr", curr, "prev_curr", prev_curr, this_digit, this_digit_i)
    return this_digit + solve(prev_curr, a - (prev_curr*(this_digit_i)))
while True:
    if curr >= a:
        ret = solve(curr, a, False)
        break
    else:
        if curr*5 < a:
            curr *= 5
        else:
            curr *=5

print(ret)
