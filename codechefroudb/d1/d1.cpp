#include<iostream>
#include<vector>
using namespace std;
using LL = long long;
void dfs(vector<int>& hist, int i, int n, int& ret){
    const int N = hist.size();
    if (N <= 2){
        ret = max(ret, N);
       for (int i = 1; i <=n ;++i){
            hist.push_back(i);
            dfs(hist, i, n, ret);
            hist.pop_back();
       }
       return; 
    }
    if (2*hist[N-2] > hist[N-3] + hist[N-1]){
        ret = max(ret, N);
        for (int i = 1; i <=n ;++i){
            hist.push_back(i);
            dfs(hist, i, n, ret);
            hist.pop_back();
       } 
    }
    return;
}
int solve(int n){
    int ret = 0;
    vector<int>hist;
    for (int i = 1; i <=n ;++i){
        hist.push_back(i);
        dfs(hist, i, n, ret);
        hist.pop_back();
        }
   return ret;
}

int solve1(int k){                                                                      
    LL ret;                                                                            
   if (k == 2) {return 3;}                                               
    LL delta = (LL)k - 1ll;                                                                  
    for (LL i = 1ll; i < 1000000; ++i){                                                  
         LL sum = i*(i+1)/2;                                                           
         if (sum == delta){                                                             
            ret = 2*(i + 1);                                                            
            break;                                                                      
         } else if (sum > delta) {                                                      
            ret = 2*(LL)i;                                                                  
            break;                                                                      
         }                                                                              
    }                                                                                   
    return int(ret);                                                                
}            

int main(){
    for (int n = 100; n < 4000; ++n){
     auto ret1 = solve1(n);
     auto ret = solve(n);
     if (ret!= ret1)cout<<"WAR"<<endl;
     cout <<n <<" " << ret <<" "<< ret1<< endl;
    }
    return 0;
}
