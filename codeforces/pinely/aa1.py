dirs = [(0, 1),(0, -1),(1, 0),(-1, 0)]                                                  
def solve():                                                                            
    n = int(input())                                                                    
    coordinates = set()                                                                 
    axis0 = set()                                                                       
    axis1 = set()                                                                       
    for _ in range(n):                                                                  
        x, y = [int(c) for c in input().split()]                                        
        if x == 0 and y == 0:                                                           
            continue                                                                    
        if x > 0 and y > 0:                                                             
            coordinates.add(1)                                                          
        elif x < 0 and y > 0:                                                           
            coordinates.add(2)                                                          
        elif x < 0 and y < 0:                                                           
            coordinates.add(3)                                                          
        elif x > 0 and y < 0:                                                           
            coordinates.add(4)                                                          
        if x== 0:                                                                       
            axis1.add(y > 0)                                                            
        if y == 0:                                                                      
            axis0.add(x > 0)                                                            
    if len(coordinates) >= 3:                                                           
        return False   
   
    if sorted(coordinates) == [1, 3] or sorted(coordinates) == [2, 4]:                  
        return False                                                                    
    if sorted(coordinates) == [1, 2] and False in axis1:                                
        return False                                                                    
    if sorted(coordinates) == [2, 3] and True in axis0:                                 
        return False                                                                    
    if sorted(coordinates) == [3, 4] and True in axis1:                                 
        return False                                                                    
    if sorted(coordinates) == [1, 4] and False in axis0:                                
        return False     
        
    if sorted(coordinates) == [1, 2] and len(axis0)==2:                               
        return False                                                                    
    if sorted(coordinates) == [2, 3] and len(axis1)==2:                                        
        return False                                                                    
    if sorted(coordinates) == [3, 4] and len(axis0)==2:                                       
        return False                                                                    
    if sorted(coordinates) == [1, 4] and len(axis1)==2:                                 
        return False                       
    return True                                                                         
                                                                                        
                                                                                        
                                                                                        
                                                                                        
T = int(input())                                                                        
for i in range(T):                                                                      
    ret = solve()                                                                       
    print("YES" if ret else "NO")                                                       

