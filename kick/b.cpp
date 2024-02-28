#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include <math.h>
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


bool good(int i , int n)
{
    if (i==n) return true;
    int b = 2*i - 1;
    int a = 1, c = -2*n;
    int r = b*b - 4*a*c;
    if (r<0) return false;
    int rootr = sqrt(r);
    if (rootr * rootr != r) return false;
    if (rootr - b < 2) return false;
    if ((rootr - b)%2!=0) return false;
    return true;
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
void solve(int C, int n)
{
    int ret = 0;
    for (int i = 1; i <= n; ++i) 
       ret += good(i, n);
    cout << "Case #" <<C <<": "<<ret<<endl;     
}
int main()
{
  int T;
  cin >> T;
  for (int C = 1; C <= T; ++C)
  {
    int G;
    cin >> G;
    solve(C, G);
  }
  return 0;
}
