#include <iostream>                                                                     
#include <vector>                                                                       
#include <algorithm>                                                                    
#include <unordered_map>                                                                
using LL = long long;  
using namespace std;                                                                    
void solve(int k){                                                                      
   if (k == 2) {cout << 3 <<endl;return;}                                               
    LL delta = (LL)k - 1ll;                                                                  
    LL ret=0;                                                                            
    for (LL i = 1; i < 1000000; ++i){                                                  
         LL sum = i*(i+1)/2;                                                           
         if (sum == delta){                                                             
            ret = 2*(i + 1);                                                            
            break;                                                                      
         } else if (sum > delta) {                                                      
            ret = 2*i;                                                                  
            break;                                                                      
         }                                                                              
    }                                                                                   
    cout << ret <<endl;                                                                 
}                                                                                       
void solve1(int k){                                                                     
   if (k == 2) {cout << 3 <<endl;return;}                                               
   int ret = 2;                                                                         
   int a = 1, b = k;                                                                    
   cout << a<<endl;                                                                     
   cout << b <<endl;                                                                    
   while(true){                                                                         
       int c;                                                                           
       if (b >= a){                                                                     
          c = b + (b-a) - 1;                                                            
          if (c < 1) break;                                                             
          if (c > k) c = k;                                                             
           cout << c<<endl;                                                             
          ret ++;                                                                       
       }  else {                                                                        
          // b < a                                                                      
          c = b - (a - b) - 1;                                                          
          if (c < 1) break;                                                             
          ret++;                                                                        
          cout << c<<endl;                                                              
       }                                                                                
           a = b;                                                                       
           b = c;                                                                       
       }                                                                                
   cout << ret <<endl;                                                                  
   return;                                                                              
}                                                                                       
int main() {                                                                            
        int T; cin >> T;                                                                
        while (T--){                                                                    
            int m; cin >> m;                                                            
            solve(m);                                                                   
        }                                                                               
        return 0;                                                                       
                                                                                        
}    
