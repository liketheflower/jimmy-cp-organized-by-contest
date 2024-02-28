#include<iostream>
#include<vector>
#include<set>
#include<cstring>
#include<unordered_map>
#include <algorithm>
using namespace std;
typedef pair<int, int>PII;
typedef long long LL;
LL get_ret(vector<PII>&a){
    LL ret = 0;
    const int n = a.size();
    if (n < 2)return ret;
    vector<LL> cusum(n+1, 0);
    for (int i =1; i <=n; ++i){
	cusum[i] = cusum[i-1] + (LL)a[i-1].second;
    }
    for (int i = 1; i < n; ++i)
    {
	for(int j = 0;j < i; ++j){
	    int right = a[i].second;
	    int left = a[j].second;
	    int left_idx = a[j].first;
	    int right_idx = a[i].first - a[i].second + 1;
	    int cnt = right_idx - left_idx - 1;
	   // cout <<"cnt" <<cnt<<" "<<right_idx <<" "<<left<<endl;
	    if (cnt == 0)continue;
	    cnt -= cusum[i] - cusum[j+1];
	    ret += (LL)left*right*cnt;
	}
    }
    return ret;
}
int main(){
   int n;cin>>n;
   vector<int>nums(n, 0);
   unordered_map<int, vector<PII>> num_idx;
   for (int i = 0; i <n; ++i){
       cin >> nums[i];
       int x = nums[i];
       if (i > 0 && nums[i] == nums[i-1]){
	   auto [idx, cnt] = num_idx[x].back();
	   num_idx[x].pop_back();
	   num_idx[x].emplace_back(i, cnt+1);
       }
      num_idx[x].emplace_back(i, 1); 
   }
   LL ret = 0;
   for (auto [k, v]: num_idx){

       auto this_ret = get_ret(v);
       //cout << k <<" "<<this_ret<<endl;
       ret += this_ret;
   }
cout << ret <<endl;
return 0;
  }
