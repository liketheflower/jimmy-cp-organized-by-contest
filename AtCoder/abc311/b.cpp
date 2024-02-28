#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n, m; cin >> n >> m;
  vector<int>nums(m, 0);
  vector<string>s(n);
  for (int i = 0 ; i < n; ++i){
      cin >> s[i];
  }
  for (int j = 0; j < m; ++j){
      bool found = true;
      for (int i = 0; i < n; ++i){
	  if (s[i][j] == 'x')found = false;
      }
      nums[j] = int(found);
  }
  int ret = 0, curr_ret = 0;
  for (int i =0 ; i < m; ++i){
      if (nums[i] == 1){
	  curr_ret++;
	  ret =  max(ret, curr_ret);
      }else{
	  curr_ret = 0;
      }
  }
  cout << ret << endl;
return 0;
  }
