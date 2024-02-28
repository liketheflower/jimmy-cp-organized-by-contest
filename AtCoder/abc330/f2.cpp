#include<iostream>                                                                      
#include<vector>                                                                        
#include<unordered_set>                                                                 
using namespace std;                                                                    
int main(){                                                                             
    int n, m;                                                                           
    cin>>n >> m;                                                                        
    int color;                                                                          
    vector<unordered_set<int>> st(n + 1);                                               
    for (int i = 1; i <=n; ++i){                                                        
        cin >> color;                                                                   
        st[i].insert(color);                                                            
    }                                                                                   
    int a, b;                                                                           
    for (int i = 0; i < m; ++i){                                                        
        cin >> a >> b;                                                                  
        int sz_a = st[a].size();                                                        
        int sz_b = st[b].size();                                                        
        if (sz_a < sz_b){                                                               
            for (auto c: st[a]){                                                        
                st[b].insert(c);                                                        
            }                                                                           
        } else {                                                                        
            for (auto c: st[b]){                                                        
                st[a].insert(c);                                                        
            }                                                                           
            //st[b] = st[a];
            swap(st[b], st[a]);	    
        }                                                                               
        st[a].clear();                                                                  
        cout << st[b].size()<<endl;                                                     
    }                                                                                   
    return 0;                                                                           
} 
