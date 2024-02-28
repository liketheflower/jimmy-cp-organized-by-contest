#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
int main(){
  int n, k; cin>>n >>k;
  vector<PII>a;
  LL sum = 0;
  for (int i = 0; i <n;++i){
      int x1, x2;
      cin >> x1 >> x2;
      sum += LL(x2);
      a.emplace_back(x1, x2);
  }
  if (sum <= k){
      cout << 1 <<endl;
      return 0;
  }
  sort(a.begin(), a.end());
  int ret = 0;
  int day = 1;
  for (int i = 0; i < n; ++i){
      auto [e, f] = a[i];
      day = e;
      sum -= f;
      if (sum <= k){
	  cout << day + 1 <<endl; 
	  return 0;
      }
      
  }
  cout << day + 1<<endl;
  return 0;
}
