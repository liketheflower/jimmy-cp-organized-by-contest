import itertools
a = input()
ret = []
for c, gb in itertools.groupby(a):
    ret.append(c)
if ret == ["A", "B", "C"]:
    print("Yes")
elif len(ret) == 2 and ret in [["A", "B"], ["A", "C"], ["B", "C"]]:
    print("Yes")
elif len(ret) == 1 and ret[0] in "ABC":
    print("Yes")
elif len(ret) == 0:
    print("Yes")
else:
    print("No")
