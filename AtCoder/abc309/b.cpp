#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n; cin>>n;
  vector<string>s(n), t(n);
  for (int i = 0; i <n;++i){
      cin >> s[i];
      t[i] = s[i];
  }
  int m = s[0].size();
  // top
  for (int j = 0; j < m;++j){
      // top
      if (j == 0){
	  t[0][j] = s[1][0];
      } else {
	  t[0][j] = s[0][j-1];
      }
      // botttom
      if (j == m -1){
	  t[n-1][j] = s[n-2][j];
      } else {
	  t[n-1][j] = s[n-1][j+1];
      }
  }
  for (int i = 1; i < n-1;++i){
      // left 
	  t[i][0] = s[i+1][0];
	  t[i][m-1] = s[i-1][m-1];
      }
  for (auto x:t)cout<<x<<endl;
return 0;
  }
