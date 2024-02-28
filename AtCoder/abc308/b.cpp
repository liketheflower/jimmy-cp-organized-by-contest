#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void solve()
{   int n, m;
    cin >> n >>m;
    vector<string> eats(n);
    vector<string>colors(m);
    vector<int> prices(m + 1);

    for (int i = 1; i <= n; ++i){
	cin >> eats[i-1];
    }
    for (int i = 1; i <= m; ++i){
	cin >> colors[i-1];
    }
    for (int i = 1; i <= m+1; ++i){
	cin >>prices[i-1];
    }
    unordered_map<string, int> mp;
    for (int i = 0; i < m; ++i){
	mp[colors[i]] = prices[i+1];
    }
    int ret = 0;
    for (auto x: eats){
	if (mp.find(x) == mp.end()){
	     ret += prices[0];
	}else{
	    ret += mp[x];
	}
    }
    cout << ret << endl;
}
int main(){
  solve();
  return 0;
}
