#include<iostream>                                                                      
#include<algorithm>                                                                     
using namespace std;                                                                    
                                                                                        
                                                                                        
void solve_(string s){                                                                   
   const int n = s.size();                                                              
   string new_s;                                                                        
   /*new_s.push_back(s[n-1]);                                                             
   for (int i = n -2; i >=0; --i) {                                                     
       new_s.push_back(max(new_s.back(), s[i]));                                        
   }                                                                                    
   reverse(new_s.begin(), new_s.end()); 
   */
   string ss;
   ss.push_back(s[0]);
   for (int i = 1; i < n ;++ i){
       if (s[i] != ss.back())ss.push_back(s[i]);
    }                                                
   string ret;
   int j = 0;
   const int m = ss.size();
   char curr = s[0];                                        
   for (int i = 0; i < n - 1; ++i){   
       if (curr != ss[j])j++;                                                 
       if (s[i] < s[i+1]){                                                              
         ret += s[i];                                                                   
         ret += s[i];                                                                   
       } else if (s[i] == s[i+1] && j < m && s[i] < ss[j]){
         ret += s[i];                                                                   
         ret += s[i];                                                                   
       }else{                                                                         
         ret += s[i];                                                                   
       }                                                                                
   }                                                                                    
   ret += s[n-1];                                                                       
   cout<<ret<<endl;                                                                     
   return;                                                                              
}  

void solve(string s){
   const int n = s.size();
   //vector<string> ret;
   string ret = s;
   for (int j = 0; j < (1 << n); ++j){
      string this_ret = "";
      for (int i = 0; i < n; ++i) {
          this_ret += s[i];
          if (j & (1 << i)){
            this_ret += s[i];
          }
      }
      if (this_ret.compare(ret) < 0) ret = this_ret;
   }
   cout << ret << endl;
}                                                                                     
int main(){                                                                             
   int T; cin >> T;                                                                     
   for (int i = 1; i <= T; ++i){                                                        
      cout<<"Case #" << i << ": ";                                                       
      string s;                                                                         
      cin >> s;                                                                         
      solve(s);                                                                         
   }                                                                                    
   return 0;                                                                            
}      
