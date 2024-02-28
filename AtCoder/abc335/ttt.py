e = ["dbbbdcaaa","bbdccddad","aacdaccac","aadbdbdba","dabaabcba","dbaaabcccdccc","dcdabbcbbbbaa","dccddbddacbbc","ccbdcccaaaccc","bcbddacacaaddddcaabb","dbbccdacccdbbbadacdc","ccbdabdaabbbaacacbba","caacdccca","bbcacabdc","dbdcaadca","cacaacbcd","b","d","b","ccdd","cbdc","dabc","cbca","d","b","ac","cd","ba","db","a"]
f = ["bbdccddad","aacdaccac","aadbdbdba","dabaabcba","dcccdacad","dcdabbcbbbbaa","dccddbddacbbc","ccbdcccaaaccc","dbbbbcdccadcc","dbbccdacccdbbbadacdc","ccbdabdaabbbaacacbba","aacbcaadbcaacdabdbdc","bbcacabdc","dbdcaadca","cacaacbcd","ddbaddbca","d","b","c","cbdc","dabc","cbca","bada","b","d","cd","ba","db","bd","d"]
g = [100,92,60,96,85,58,65,47,18,75,96,37,7,97,78,92,89,55,90,64,100,95,61,86,55,83,93,31,64,64]
for a, b, c in zip(e, f, g):
    if a == 'b':
        print(a, b , c)
