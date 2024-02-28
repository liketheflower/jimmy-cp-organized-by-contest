       """
        (a*a) % k == r1
        (b*b) % k == r2
        (a+b)*(a+b) = a*a + b*b + 2*a*b
        e = []
        
        """ 
        n = len(s)
        e = [0 for _ in range(n+1)]
        v = [0 for _ in range(n+1)]
        for i, c in enumerate(s):
            e[i+1] = e[i]
            v[i+1] = v[i]
            if c in "aeiou":
                e[i+1] += 1
            else:
                v[i+1] += 1
        print(e)
        print(v)
        return 0
    """
    a2 - a1 = b2 - b1
    a2 - b2 = a1 - b1
    a2 - a1 = a
    a*a % k = r1
    (a-b)*(a-b) = a*a + b*b - 2*a*b
    a*a % k + b*b % k = 2*a*b % k
    aa%k = 2*a*b%k - b*b%k
    
    """
