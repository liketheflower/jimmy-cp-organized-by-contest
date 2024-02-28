#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
int main(){
   int n;cin>>n;
   vector<unordered_set<int>> bets(n);
   vector<int>nums(n);
   for (int i = 0; i < n; ++i){
       int m ; cin >> m;
       nums[i] = m;
       for (int j = 0; j < m; ++j){
	   int this_num;
	   cin >> this_num;
	   bets[i].insert(this_num);
       }
   }
   int x; cin >> x;
   vector<PII> ret;
   for (int i = 0; i < n; ++i ){
      if (bets[i].find(x) != bets[i].end()){
	  ret.emplace_back(nums[i], i);
      }
   }
   sort(ret.begin(), ret.end());
   vector<int> fin_ret;
   if (ret.empty()){
       cout << 0 <<endl;
       return 0;
   }
   int min_b = ret[0].first;
   for (auto [r, i]: ret){
       if (r == min_b)fin_ret.push_back(i + 1);
   }
   cout << fin_ret.size() << endl;
   for (auto ele:fin_ret)cout << ele << " ";
   cout << endl;
return 0;
  }
