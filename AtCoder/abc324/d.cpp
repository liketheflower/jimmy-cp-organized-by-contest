#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;
typedef long long LL;
int main(){
    int n;
    cin >> n;
    vector<int>nums(n,0 );
    unordered_map<LL, LL> cnt;
    for (int i = 0; i < n; ++i){
	int s, c;
	cin  >> s >> c;
	nums[i]= s;
	cnt[s] = c;
    }
    //sort(nums.begin(), nums.end());
    set<LL>candidates;
    for (auto x:nums){
	candidates.insert((LL)x);
    }
    while(!candidates.empty()){
	auto cand = *candidates.begin();
	candidates.erase(candidates.begin());
	LL new_val = (LL)cand*2;
	LL new_cnt = cnt[cand] / 2;
//	cout << new_val <<" "<< new_cnt<<endl;
	if (new_cnt == 0)continue;
	cnt[cand] -= 2*new_cnt;
	cnt[new_val] += new_cnt;
	candidates.insert(new_val);
    }
    LL ret = 0;
    for (auto [k, v]: cnt){
	ret += v;
    }
    cout << ret << endl;
return 0;
  }
