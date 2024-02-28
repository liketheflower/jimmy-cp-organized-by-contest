#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int K= 1e5+10;
long long cnt1[K];
int main()
{
  int N;
  long long ret = 0;
  cin >> N;
  memset(cnt1, 0, sizeof cnt1);
  vector<int> a(N+1, 0), b(N+1, 0), c(N+1, 0);
  for (int i = 1; i <= N; ++i)
    cin >> a[i];
  for (int i = 1; i <= N; ++i)
    cin >> b[i];
  for (int i = 1; i <= N; ++i)
    cin >> c[i];
  //for (auto &x : b)cnt[x]=1;
  for (auto &x : c)cnt1[b[x]] ++;
  //cout<<cnt1[1]<<endl;
  for (auto &x : a)
      ret += cnt1[x];
  cout << ret - 1 << endl; 
  return 0;  
}

