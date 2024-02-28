s = input()
ret = s[0] == s[0].upper() and s[1:] == s[1:].lower()
print("Yes" if ret else "No")
