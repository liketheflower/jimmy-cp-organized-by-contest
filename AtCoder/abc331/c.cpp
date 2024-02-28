#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
int main(){
    int n;
    cin>>n;
    vector<int>a(n, 0);
    vector<PII>ai;
    for (int i = 0; i < n; ++i){
	cin >> a[i];
	ai.emplace_back(a[i], i);
    }
    sort(ai.begin(), ai.end());
    vector<LL> cusum(n+1, 0);
    for (int i  = 1; i <=n; ++i){
	cusum[i] += cusum[i-1] + (LL)ai[i].first;
    }
    vector<LL>ret(n, 0);
    for (int i = 0; i <n ;++i){
       PII key = {ai[i].first, n + 1};
       int j = upper_bound(ai.begin(), ai.end(), key) - ai.begin();
       if (j != n){
	   LL this_ret = cusum.back() - cusum[j-1];
	  ret[ai[i].second] = this_ret; 
       }
    }
   for (auto x: ret)cout << x <<" ";
    cout << endl;
return 0;
  }
