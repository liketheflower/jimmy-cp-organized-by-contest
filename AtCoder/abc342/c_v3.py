from functools import lru_cache                                                         
N = int(input())                                                                        
@lru_cache(None)                                                                        
def f(n):                                                                               
    if n <= 1:                                                                          
        return 0                                                                        
    else:                                                                               
        if n % 2 == 0:                                                                  
            half = n // 2                                                               
            return n + 2*(f(half))                                                      
        else:                                                                           
            half = int(n / 2)                                                           
            return n + f(half) + f(half + 1)                                            
print(f(N)) 
