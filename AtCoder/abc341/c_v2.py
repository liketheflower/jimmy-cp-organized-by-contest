from functools import lru_cache                                                         
N = int(input())                                                                                                                                                   
@lru_cache(None)                                                                        
def f(n):                                                                               
    if n <= 1:                                                                          
        return 0                                                                        
    else: 
        half = n // 2                                                                             
        if n % 2 == 0:                                                                                                                
            return n + 2*(f(half))                                                      
        else:                                                                                                                  
            return n + f(half) + f(half + 1)                                            
print(f(N))
