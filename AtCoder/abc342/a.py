import collections
s = input()
cnt = collections.Counter(s)
c = [k for k, v in cnt.items() if v == 1]
print(s.index(c[0]) + 1)
