d = int(input())
half_d = d//2
delta = 10
h = int(d**0.5)
def get_y(x):
    remain = abs(d - x*x)
    remain = int(remain**0.5)
    return [remain-1, remain, remain+1]
candidates = [[x, y] for x in range(h + 1) for y in get_y(x)]
ret = min(abs(x*x + y*y-d) for x,y in candidates)
print(ret)
