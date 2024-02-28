#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
const int MOD = 1e9+7;
vector<string> dfs(string a, int i, int k) 
{    
    vector<string> ret;
    ret.push_back("");
    if (i == k) return ret;
    auto thisRet = dfs(a, i+1, k);
    for (auto r : thisRet) 
    {
        for (auto x : a) 
        {
            ret.push_back(x + r);
        }
    }
    return ret;
}

bool valid(string s, string s1, int m)
{
  int n = s.size();
  if (n!=m) return false;
  if (n==0) return false;
  if (s >= s1) return false;
  if (n==1) return true;
  int i = 0, j = n - 1;
  while (i < j)
  {
    if (s[i++]!=s[j--])return false;
  }
  return true;
}
void solve(int C, int n, int k, string s)
{
    string a ="";
    for (int i = 0; i < k; ++i) 
    {
      a += 'a' + i;
    }
    auto ret = dfs(a, 0, n);
    int fin_ret = 0;
    for (auto r: ret)
    {
        //cout<<r<<endl;
        fin_ret += valid(r, s, n);
    }
    fin_ret %= MOD;
    cout << "Case #" <<C <<": "<<fin_ret<<endl;
}
int main()
{
  int T;
  cin >> T;
  for (int C = 1; C <= T; ++C)
  {
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    solve(C, N, K, s);
  }
  return 0;
}
