a = input()
b = input()
target = "ABCDE"
a1, a2 = [target.index(c) for c in a]
b1, b2 = [target.index(c) for c in b]
diff_a = abs(a1-a2)
diff_b = abs(b1-b2)
diff_a =  min(diff_a, 5 - diff_a)
diff_b = min(diff_b, 5 - diff_b)
if diff_a == diff_b:
    print("Yes")
else:
    print("No")

