a = int(input())
b = bin(a)[2:]
ret = 0
for c in b[::-1]:
    if c  == '1':
        break
    ret += 1
print(ret)
