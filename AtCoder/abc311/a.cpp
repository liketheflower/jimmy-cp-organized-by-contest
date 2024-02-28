#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n; cin >> n;
  string s;cin >>s;
  int ret = 0;
  int a[3] = {0, 0, 0};
  for (int i = 0; i < n; ++i){
      a[s[i] - 'A'] = 1;
      bool found = true;
      for (int j  =0 ; j < 3; ++j){
	 if (a[j] != 1)found = false;
      }
      if (found){
	  ret = i +1;
	  break;
      }
  }
  cout << ret<<endl;

return 0;
  }
