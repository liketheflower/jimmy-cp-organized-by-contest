#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> PII;
int main(){
    int n;
    cin >> n;
    string s;
    vector<int>cnt(n, 0);
    for (int i = 0; i < n; ++i){
	cin >> s;
	for (int j = 0; j < n; ++j){
	    if (s[j] == 'o')cnt[i]++;
	}
    }
    vector<PII> fin_ret;
    for (int i = 0; i < n; ++i){
	fin_ret.emplace_back(cnt[i], -i);
    }
    sort(fin_ret.begin(), fin_ret.end());
    reverse(fin_ret.begin(), fin_ret.end());
    for (auto [k, idx]: fin_ret) cout << (-idx) + 1 <<" ";
    cout << endl;
return 0;
  }
