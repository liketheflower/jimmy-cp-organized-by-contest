#include<iostream>
#include <utility>
#include<vector>
using namespace std;
typedef pair<int, int> PII;
int main(){
  int n;
  cin >> n;
  vector<int> ret(n, 0);
  vector<int> cnt(n, 0);
  
  
  for (int i = 0; i < 3*n; ++i)
  {
      int num;
      cin >> num;
      int idx = num - 1;
      //cout << idx <<endl;
      cnt[idx] ++;
      if (cnt[idx] == 2){
	  ret[idx] = i;
      }
  }
//for (auto x:ret)cout<<x<<" ";
  vector<PII>fin_ret(n);
  for (int i = 0; i < n; ++i){
      fin_ret[i] = make_pair(ret[i], i + 1);
  }
  sort(fin_ret.begin(), fin_ret.end());
  for (auto [x, i]: fin_ret)cout << i <<" ";
  return 0;
}
