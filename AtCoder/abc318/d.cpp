#include<iostream>
#include<vector>
#include<set>
#include<cstring>
int cost[20][20];
using namespace std;
typedef long long LL;

LL memo[65536+10];
LL dp(int mask, int n){
    if (memo[mask] != -1)return memo[mask];
    LL ret = 0;
    for (int i = 0; i < n; ++i){
	if ((mask &(1<<i)) == 0){
	    int new_mask = mask | (1<<i);
	    for (int j = 0; j < n; ++j){
	        if ((mask &(1<<j)) == 0){
		    int new_new_mask = new_mask | (1 << j);
		    auto this_ret = (LL)cost[i][j] + dp(new_new_mask, n);
		    ret = max(ret, this_ret);
		}
	    }
	}
    }
    return memo[mask] = ret;
}
int main(){
   int n;cin>>n;
   memset(cost, 0, sizeof cost);
   memset(memo, -1, sizeof memo);
   for (int i = 0; i <n-1; ++i){
       for (int j = i+1; j <n;++j){
	   int this_cost;
	   cin >> this_cost;
	   cost[i][j] = this_cost;
	   cost[j][i] = this_cost;
       }
   }
   int mask = 0;
   auto ret = dp(mask, n);
   cout << ret << endl;

return 0;
  }
