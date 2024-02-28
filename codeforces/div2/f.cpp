#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
void solve(){
int n; cin >> n;
vector<PII>nums(n);
int a, b;
for (int i = 0; i < n; ++i){
    cin >> a >> b;
    nums[i] = {a, b};
}
sort(nums.begin(), nums.end());
set<int> bs;
LL ret = 0ll;
for(auto [a, b]: nums){
    int this_ret =distance(bs.upper_bound(b), bs.end());
    ret += LL(this_ret);
    bs.insert(b);
}
cout << ret << endl;
}
int main(){
    int T; cin >> T;
    while (T--)solve();
    return 0;
}
