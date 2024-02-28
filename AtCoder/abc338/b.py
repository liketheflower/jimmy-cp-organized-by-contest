import collections
s = input()
cnt = collections.Counter(s)
max_f = max(cnt.values())
ret = min(k for k, v in cnt.items() if v== max_f)
print(min(ret))
