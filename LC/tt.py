import collections
from typing import List
class Solution:
    def maxPalindromesAfterOperations(self, words: List[str]) -> int:
        word = "".join(words)
        cnt = collections.Counter(word)
        print(cnt)
        ret = 0
        odd = []
        even = []
        for v in cnt.values():
            if v % 2 ==0:
                even.append(v)
            else:
                odd.append(v)
        def check(n, even, odd):
            this_even = even[:]
            this_odd = odd[:]
            success = True
            print("1",n, this_even, this_odd)
            while True:
                if n % 2 ==1:
                    if this_odd:
                        num = this_odd.pop()
                        if num > 1:
                            this_even.append(num - 1)
                    else:
                        if not this_even:
                            success = False
                            break
                        else:
                            num = this_even.pop()
                            this_odd.append(num - 1)
                    print(n, this_even, this_odd)
                    n -= 1
                else:
                    print("-- ", n, this_even, this_odd)
                    if sum(this_even) + sum(this_odd) - len(this_odd) < n:
                        success = False
                        break
                    else:
                        print(this_even, this_odd)
                        while True:
                            while this_even:
                                old_n = n
                                num = this_even.pop()
                                n -= num
                                if n < 0:
                                    this_even.append(num - old_n)
                                    n = 0
                                    break
                                if n == 0:
                                    break
                            if n == 0:
                                break
                            for i in range(len(this_odd)):
                                if this_odd[i] - 1 <= n:
                                    n -= (this_odd[i]-1)
                                    this_odd[i] = 1
                                    if n == 0:
                                        break
                                else:
                                    this_odd[i] -= n
                                    n = 0
                                    break
                            if n == 0:
                                break
                            else:
                                success = False
                                break
                        if success:
                            return success, this_even, this_odd
                        else:
                            return success, even, odd
            if success:
                return success, this_even, this_odd
            else:
                return success, even, odd
            
                                        
        len_w = [len(w) for w in words]
        len_w.sort()
        for w in len_w:
            this_ret, even, odd = check(w, even, odd)                             
            
            print(this_ret, even, odd)
            ret += int(this_ret)
        return ret
s = Solution()

words = ["rqfsx","kja","mx","r"]
print(s.maxPalindromesAfterOperations(words))        
