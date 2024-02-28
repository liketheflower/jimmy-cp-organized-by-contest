#include<iostream>
#include<vector>
#include<set>
#include<cstring>
#include<unordered_set>
#include <algorithm>
int memo[11][11];
using namespace std;
typedef long long LL;


int main(){
   int n, d, p;cin>>n>>d>>p;
   vector<int> costs(n, 0);
   for (int i = 0; i <n; ++i){
       cin >> costs[i];
   }
   sort(costs.begin(), costs.end(), greater<int>());
   
   LL ret = 0;
   int i = 0;
   while (true){

       LL curr_ret = 0;
       for (int j = 0; j < d; ++j){
	   int k = i + j;
	   if (k < n)curr_ret += costs[k];
	   else {
	       ret += curr_ret > p?p:curr_ret;
	       cout << ret <<endl;
	       return 0;
	   }
       }
       i += d;
       ret += curr_ret > p?p:curr_ret;
   }
return 0;
  }
