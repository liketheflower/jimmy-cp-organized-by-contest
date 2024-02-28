#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
void solve(int C, int W, int E)
{
    string ret ="R";
    int r=1, s=0, p=0;
    double R, S, P;
    for (int i = 1; i < 60; ++i) 
    {
      char thisRet;
      R =  double(s)/i;
      P =  double(r)/i;
      S =  double(p)/i;
      double mx = 0;
      if (R > mx) {
      mx = R;
      thisRet = 'P';
      }
      if (P > mx) {
      mx = P;
      thisRet = 'S';
      }
      if (S > mx) {
      mx = S;
      thisRet = 'R';
      }
      if (thisRet == 'R') r++;
      if (thisRet == 'P') p++;
      if (thisRet == 'S') s++;
    
      ret.push_back(thisRet);
    }
    cout << "Case #" <<C <<": "<<ret<<endl;
}
int main()
{
  int T, X;
  cin >> T;
  cin >> X;
  for (int C = 1; C <= T; ++C)
  {
    int W, E;
    cin >> W >> E;
    solve(C, W, E);
  }
  return 0;
}
